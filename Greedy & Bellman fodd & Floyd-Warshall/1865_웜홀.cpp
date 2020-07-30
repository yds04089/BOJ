#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 987654321
vector<pair<int, int>> arr[503];
int dist[503];

int bellman_fodd(int n)		//벨만포드 알고리즘
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				//if (dist[from] == INF) break;		//출발점이 INF여도 무시하면 안됨 (출발점이 어딘지 모르기 때문)
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
	int tc;
	scanf("%d", &tc);
	for (int z = 0; z < tc; z++) {
		int n, m, w;
		scanf("%d%d%d", &n, &m, &w);
		for (int i = 1; i <= n; i++) {
			arr[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < m; i++) {	//도로 입력받음
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			arr[from].push_back(make_pair(to, cost));
			arr[to].push_back(make_pair(from, cost));
		}
		for (int i = 0; i < w; i++) {	//웜홀 입력받음
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			arr[from].push_back(make_pair(to, -cost));
		}
		dist[1] = 0;	//임의로 출발점을 1로 했지만 어딜 해도 상관없음
		int check = bellman_fodd(n);
		if (check == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}