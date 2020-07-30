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

const int INF = 1001;
vector<pair<int, int>>arr[801];		//<노드, 비용>
priority_queue <pair<int, int>> pq;		//<비용(*-1), 노드>
int dist[801];						//최단거리 저장 배열

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
			if (dist[now] + next_cost < dist[next]) {
				dist[next] = dist[now] + next_cost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main()
{
	int n, e, n1, n2;
	scanf("%d%d", &n, &e);
	for (int i=0; i<e; i++){
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
		arr[to].push_back(make_pair(from, cost));
	}
	scanf("%d%d", &n1, &n2);
	int start_n1, start_n2, n1_n2, n2_n1, n2_n, n1_n;
	for (int i = 0; i <= n; i++) dist[i] = INF;		//각각 구간마다 다익스트라를 이용해 각각 최단 거리를 구해냄
	dijkstra(1);
	start_n1 = dist[n1];
	start_n2 = dist[n2];
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dijkstra(n1);
	n1_n2 = dist[n2];
	n1_n = dist[n];
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dijkstra(n2);
	n2_n1 = dist[n1];
	n2_n = dist[n];
	int result1 = start_n1 + n1_n2 + n2_n;
	int result2 = start_n2 + n2_n1 + n1_n;
	if (start_n1 + n1_n2 + n2_n >= INF && start_n2 + n2_n1 + n1_n >= INF)	//만약 갈 수 없는 길이라면 -1 출력
		printf("-1\n");
	else if (result1 < result2)
		printf("%d\n", result1);
	else
		printf("%d\n", result2);
	return 0;
}