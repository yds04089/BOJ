#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[32001];
queue<int> q;
vector<int> tmparr;
int res[32001];
int indegree[32001];

int tropological(int n)	//위상정렬
{
	for (int i = 1; i <= n; i++)	//indegree가 0이면 q에 삽입
		if (indegree[i] == 0)
			q.push(i);
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		q.pop();
		res[idx++] = now;		//q에서 pop되는 순서대로 결과값에 삽입
		for (int i = 0; i < arr[now].size(); i++) {
			if (--indegree[arr[now][i]] == 0)	
				q.push(arr[now][i]);
		}
	}
	if (idx == n)	//끝까지 가고나서 q가 비었으면 사이클 없음
		return 0;
	else			//n까지 가기 전에 큐가 비게되면 사이클 있음
		return 1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int small, big;
		scanf("%d%d", &small, &big);
		arr[small].push_back(big);
		indegree[big]++;
	}
	tropological(n);
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}