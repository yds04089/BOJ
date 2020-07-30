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
vector <pair<int, int>> arr[20001];		//<x, y, 비용>
priority_queue <pair<int, int>> pq;		//<비용(*-1), 노드>
int dist[20001];						//최단거리 저장 배열

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push(make_pair(0, start));		//시작점 push
	while (!pq.empty()) {
		int now_node, now_cost;
		now_node = pq.top().second;		//현재 노드
		now_cost = -pq.top().first;	//현재 노드까지의 비용
		pq.pop();
		if (dist[now_node] < now_cost) continue;	//만약 이미 현재노드까지의 최단거리가 있다면 무시
		for (int i = 0; i < arr[now_node].size(); i++) {
			int next_node, next_cost;
			next_node = arr[now_node][i].first;
			next_cost = arr[now_node][i].second;
			if (dist[next_node] > dist[now_node] + next_cost) {	//새로운 최단거리 나타난다면
				dist[next_node] = dist[now_node] + next_cost;
				pq.push(make_pair(-dist[next_node], next_node));	//음수처리해서 priority queue에 넣음
			}
		}
	}
}

int main()
{
	int v, e, k;
	scanf("%d%d%d", &v, &e, &k);
	for (int i = 0; i <= v; i++) dist[i] = INF;		//최단거리 배열을 무한대값으로 초기화
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}