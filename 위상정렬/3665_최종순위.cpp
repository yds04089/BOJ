#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[501];
queue<int> q;	
int res[501];	
int indegree[501];


int tropological(int n)	//위상정렬
{
	while (!q.empty())		//q 초기화
		q.pop();
	for (int i = 1; i <= n; i++)	//indegree가 0이면 q에 삽입
		if (indegree[i] == 0) {	
			q.push(i);		
		}
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		res[idx] = now;
		if (q.size() > 1)		//q에 한번에 여러개 들어가 있는 경우 (결과값이 여러가지됨)
			return 2;
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (--indegree[next] == 0)
				q.push(next);
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
		int n, tmparr[501];
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {	//초기화
			arr[i].clear();
			res[i] = 0;
			indegree[i] = 0;
			
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmparr[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {	//모든 상대적 순위를 arr에 삽입
				arr[tmparr[i]].push_back(tmparr[j]);
				indegree[tmparr[j]]++;
			}
		}
		int m;
		scanf("%d", &m);
		while (m--) {
			int n1, n2, pass=0;
			scanf("%d%d", &n1, &n2);
			for (int i = 0; i < arr[n1].size();) {	//순위가 바뀐 팀을 찾아 arr에 다시 저장
				if (arr[n1][i] == n2) {
					arr[n1].erase(arr[n1].begin() + i);
					arr[n2].push_back(n1);
					indegree[n1]++;
					indegree[n2]--;
					pass = 1;
					break;
				}
				else
					i++;
			}
			if (pass == 1) continue;
			for (int i = 0; i < arr[n2].size();) {
				if (arr[n2][i] == n1) {
					arr[n2].erase(arr[n2].begin() + i);
					arr[n1].push_back(n2);
					indegree[n1]--;
					indegree[n2]++;
					break;
				}
				else
					i++;
			}
		}
		int check;
		check = tropological(n);	//위상정렬
		if (check == 1)
			printf("IMPOSSIBLE");
		else if (check == 0) 
			for (int i=0; i<n; i++)
				printf("%d ", res[i]);
		else
			printf("?");
		printf("\n");
	}
	return 0;
}