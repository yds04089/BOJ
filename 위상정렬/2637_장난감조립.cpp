#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<pair<int, int>> arr[101];
queue<int> q;	
int need[101][101];		//i를 만드는데 필요한 j의 개수 저장
int indegree[101];
vector<int> basic;		//기본부품 저장

int tropological(int n)	//위상정렬
{
	for (int i = 1; i <= n; i++)	//indegree가 0이면 q에 삽입
		if (indegree[i] == 0) {	
			need[i][i] = 1;		//기본부품인지 확인할 때 사용
			q.push(i);		
			basic.push_back(i);
		}
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int cost = arr[now][i].second;
			if (need[now][now] == 1) {	//기본부품일때
				need[next][now] += cost;
			}
			else {
				for (int i = 1; i <= n; i++) {	//중간부품일때
					if (need[now][i] > 0) {
						need[next][i] += need[now][i] * cost;
					}
				}
			}
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
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		arr[y].push_back(make_pair(x, k));
		indegree[x]++;
	}
	int check;
	check = tropological(n);	//위상정렬
	if (check == 1)
		return 0;
	for (int i = 0; i < basic.size(); i++) 
		printf("%d %d\n", basic[i], need[n][basic[i]]);
	return 0;
}