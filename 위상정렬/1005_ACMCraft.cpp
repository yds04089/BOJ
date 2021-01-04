#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[1001];
queue<int> q;	//작은걸 먼저 풀어야되므로 priority queue 씀
int res[1001];
int indegree[1001];
int time[1001];

int tropological(int n)	//위상정렬
{
	for (int i = 1; i <= n; i++)	//indegree가 0이면 q에 삽입
		if (indegree[i] == 0) {		//res에 time값도 삽입
			q.push(i);
			res[i] = time[i];	
		}
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		q.pop();	
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			res[next] = max(res[next], res[now] + time[next]);
				//next의 결과값은 기존의 next결과값과 now까지의 결과값에 next의 시간을 더한 값 중 더 큰게 된다.
			if (--indegree[next] == 0) {
				q.push(next);
			}		
		}
		idx++;
	}
	if (idx == n)	//끝까지 가고나서 q가 비었으면 사이클 없음
		return 0;
	else			//n까지 가기 전에 큐가 비게되면 사이클 있음
		return 1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k; 
		scanf("%d %d", &n, &k);
		for (int i = 0; i <= n; i++) {	//test case여러개이므로 매번 초기화
			arr[i].clear();
			time[i] = 0;
			res[i] = 0;
			indegree[i] = 0;
		}
		for (int i = 1; i <= n; i++) 
			scanf("%d", &time[i]);
		for (int i = 1; i <= k; i++) {
			int n1, n2;
			scanf("%d%d", &n1, &n2);
			arr[n1].push_back(n2);
			indegree[n2]++;
		}
		int check = tropological(n);	//위상정렬
		if (check == 1)
			return 0;
		int w;
		scanf("%d", &w);
		printf("%d\n", res[w]);
	}
	return 0;
}