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
int arr[126][126];		//<노드, 비용>
priority_queue <pair<int, pair<int, int>>> pq;		//<비용(*-1), 노드>
int dist[126][126];						//최단거리 저장 배열
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dijkstra(int n)
{
	pq.push(make_pair(-arr[1][1], make_pair(1, 1)));
	dist[1][1] = arr[1][1];
	while (!pq.empty()) {
		pair<int, int> now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		if (dist[now.first][now.second] < now_cost) continue;
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(now.first + dx[i], now.second + dy[i]);
			if (next.first <= 0 || next.second <= 0 || next.first > n || next.second > n) continue;
			int next_cost = arr[next.first][next.second];
			if (dist[next.first][next.second] > dist[now.first][now.second] + next_cost) {
				dist[next.first][next.second] = dist[now.first][now.second] + next_cost;
				pq.push(make_pair(-dist[next.first][next.second], next));
			}
		}
	}
}

int main()
{
	int n;
	vector<int> ans;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;				//0 입력받으면 종료
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
				dist[i][j] = INF;		//dist배열도 매번 초기화
			}
		dijkstra(n);
		ans.push_back(dist[n][n]);		//정답들을 배열에 넣어줌
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("Problem %d: %d\n", i + 1, ans[i]);
	}
	return 0;
}