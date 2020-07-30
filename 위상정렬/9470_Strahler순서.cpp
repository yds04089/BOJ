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
queue<int> q;	
int res[1001];		//결과값
int indegree[1001];
int maxnum[1001][2];	//각 노드별 <최댓값, 최댓값의 개수>

int tropological(int n)	//위상정렬
{
	for (int i = 1; i <= n; i++)	//indegree가 0이면 q에 삽입
		if (indegree[i] == 0) {		
			q.push(i);
			res[i] = 1;				//res값도 1 삽입
			maxnum[i][0] = 1;
			maxnum[i][1] = 1;
		}
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		q.pop();
		if (maxnum[now][1] > 1) {	//pop해서 나온 노드의 최댓값개수가 2이상이면 최댓값 1증가
			maxnum[now][0]++;
			maxnum[now][1] = 1;
		}
		res[now] = maxnum[now][0];
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (maxnum[next][0] == 0) {	//next 순서값이 0인 경우
				maxnum[next][0] = maxnum[now][0];
				maxnum[next][1] = 1;
			}
			else if (maxnum[next][0] == maxnum[now][0]) {	//next의 최댓값이 now최대랑 같은경우
				maxnum[next][1]++;
			}
			else if (maxnum[next][0] < maxnum[now][0]) {	//now최댓값이 next보다 큰 경우
				
				maxnum[next][0] = maxnum[now][0];
				maxnum[next][1] = 1;
			}
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
		int k, m, p; 
		scanf("%d %d %d", &k, &m, &p);
		for (int i = 0; i <= m; i++) {	//test case여러개이므로 매번 초기화
			arr[i].clear();
			res[i] = 0;
			indegree[i] = 0;
			maxnum[i][0] = 0;
			maxnum[i][1] = 0;
		}
		for (int i = 1; i <= p; i++) {
			int n1, n2;
			scanf("%d%d", &n1, &n2);
			arr[n1].push_back(n2);
			indegree[n2]++;
		}
		int check;
		check = tropological(m);	//위상정렬
		if (check == 1)
			return 0;
		printf("%d %d\n", k, res[m]);
	}
	return 0;
}