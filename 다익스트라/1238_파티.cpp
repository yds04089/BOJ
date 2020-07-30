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

const int INF = INT_MAX;
vector <pair<int, int>> arr[1001];		//<노드, 비용>
priority_queue <pair<int, int>> pq;		//<비용(*-1), 노드>
int dist[1001];						//최단거리 저장 배열

void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		if (dist[now] < now_cost) continue;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int next_cost = arr[now][i].second;
			if (dist[next] > arr[now][i].second + dist[now]) {
				dist[next] = arr[now][i].second + dist[now];
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main()
{
	int n, m, x, max = 0;
	int from_x[1001];
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	for (int j = 0; j <= n; j++) dist[j] = INF;
	dijkstra(x);
	for (int j = 1; j <= n; j++) from_x[j] = dist[j];	//x에서 집으로 돌아가는 최단경로들
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) dist[j] = INF;		//각각 집에서 x로가는 최단경로들
		dijkstra(i);
		if (max < dist[x] + from_x[i])			//최단경로들 중 최댓값 구함
			max = dist[x] + from_x[i];
	}
	printf("%d\n", max);
	return 0;
}