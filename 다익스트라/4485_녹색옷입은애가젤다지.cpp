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
int arr[126][126];		//<���, ���>
priority_queue <pair<int, pair<int, int>>> pq;		//<���(*-1), ���>
int dist[126][126];						//�ִܰŸ� ���� �迭
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
		if (n == 0) break;				//0 �Է¹����� ����
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
				dist[i][j] = INF;		//dist�迭�� �Ź� �ʱ�ȭ
			}
		dijkstra(n);
		ans.push_back(dist[n][n]);		//������� �迭�� �־���
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("Problem %d: %d\n", i + 1, ans[i]);
	}
	return 0;
}