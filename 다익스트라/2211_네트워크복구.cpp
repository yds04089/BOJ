#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF INT_MAX;
vector <pair<int, int>> arr[1001];		//<노드, 비용>
priority_queue <pair<int, int>> pq;	//<비용(*-1), 노드>
int dist[1001];			//최단거리 저장 배열 
int prevArr[1001];		//이전 노드 저장하는 배열
								
void dijkstra()
{
	
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		if (dist[now] < now_cost) continue;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int next_cost = arr[now][i].second;
			if (dist[next] > dist[now] + next_cost) {
				dist[next] = dist[now] + next_cost;
				pq.push(make_pair(-dist[next], next));
				prevArr[next] = now;		//최단거리 바뀔때마다 이전 노드 어디였는지 저장
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
		arr[to].push_back(make_pair(from, cost));
	}
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dijkstra();
	int cnt = 0;
	for (int i = 1; i <= n; i++)	//이어져있는 간선들 개수 구하기
		if (prevArr[i] != 0)
			cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)	//이어져있는 간선들 출력
		if (prevArr[i] != 0)
			printf("%d %d\n", i, prevArr[i]);
	return 0;
}