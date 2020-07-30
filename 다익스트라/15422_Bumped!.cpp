#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
#include<utility>
#include<limits.h>
using namespace std;

#define INF LLONG_MAX;
vector <pair<int, int>> arr[50001];		//<노드, 비용>
priority_queue <pair<pair<long long, int>, int>> pq;	//<비용(*-1), 노드>, 항공권 탔는지>
long long dist[50001][2];			//최단거리 저장 배열(항공권X, 항공권O) 
									//수가 크므로 long long 사용
void dijkstra(int start)
{
	pq.push(make_pair(make_pair(0, start), 0));
	dist[start][0] = 0;
	while (!pq.empty()) {
		int now = pq.top().first.second;
		long long now_cost = -pq.top().first.first;
		int isFlight = pq.top().second;		//항공권 썼는지 여부
		pq.pop();
		if (dist[now][isFlight] < now_cost) continue;	//이미 최단거리 있으면 무시
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			long long next_cost = arr[now][i].second;
			if (next_cost == 0 && isFlight == 1) continue;	//이미 항공권 썼는데 또 항공권 나온 경우 무시
			if (next_cost == 0 && isFlight == 0) {			//아직 항공권 안썼는데 항공권 나온 경우
				isFlight = 1;
				if (dist[next][isFlight] > next_cost + dist[now][0]) {
					dist[next][isFlight] = next_cost + dist[now][0];
					pq.push(make_pair(make_pair(-dist[next][isFlight], next), isFlight));
				}
			}
			else {							//일반 도로로 가는 경우
				if (dist[next][isFlight] > next_cost + dist[now][isFlight]) {
					dist[next][isFlight] = next_cost + dist[now][isFlight];
					pq.push(make_pair(make_pair(-dist[next][isFlight], next), isFlight));
				}
			}
		}
	}
}

int main()
{
	int n, m, f, s, t;
	scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
	for (int i = 0; i < m; i++) {		//일반 도로 추가
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
		arr[to].push_back(make_pair(from, cost));
	}
	for (int i = 0; i < f; i++) {		//항공권 추가
		int u, v;
		scanf("%d%d", &u, &v);
		arr[u].push_back(make_pair(v, 0));
	}
	for (int i = 0; i <= n; i++) {		//최단거리 초기화
		dist[i][0] = INF; 
		dist[i][1] = INF;
	}
	dijkstra(s);
	printf("%lld\n", min(dist[t][0], dist[t][1]));
	return 0;
}