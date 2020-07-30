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
vector<int> tmparr;
int res[1001];
int indegree[1001];

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
		int num;
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			int tmp;
			scanf("%d", &tmp);
			tmparr.push_back(tmp);
		}
		for (int i = 0; i < num-1; i++) {
			int now = tmparr[i];
			int next = tmparr[i + 1];
			indegree[next]++;
			arr[now].push_back(next);
		}
		tmparr.clear();
	}
	int check = tropological(n);
	if (check == 1) {	//사이클 있는 경우
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++)	//사이클 없는 경우
		printf("%d\n", res[i]);
	return 0;
}