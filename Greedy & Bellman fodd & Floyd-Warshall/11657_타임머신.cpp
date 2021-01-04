#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 923456789
vector<pair<int, int>> arr[501];
int dist[501];

int bellman_fodd(int n)		//벨만포드 알고리즘
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				if (dist[from] == INF) break;		//출발점이 INF면 무시
				if (dist[to] > dist[from] + arr[i][j].second) {	//최단거리 업데이트
					dist[to] = dist[from] + arr[i][j].second;
					if (k == n)		//n번째에도 업데이트가 되면 음수로 인해 사이클 생긴것
						return 1;
				}
			}
		}
	}
	return 0;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	for (int i = 1; i <= n; i++)
			dist[i] = INF;
	dist[1] = 0;
	int check = bellman_fodd(n);	
	if (check == 1) {		//사이클 생겼으면 -1출력하고 종료
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= n; i++){
		if (dist[i] == INF)	//특정 노드까지 최단거리 없으면 -1 출력
			dist[i] = -1;
		printf("%d\n", dist[i]);
	}
	return 0;
}