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
int arr[101][101];		//<x, y, ���>
priority_queue <pair<int,pair<int, int>>> pq;		//<���(*-1), <x, y>>
int dist[101][101];						//�ִܰŸ� ���� �迭
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dijkstra(int n, int m)
{
	pq.push(make_pair(0, make_pair(1, 1)));			//������  pq �� ����
	dist[1][1] = 0;
	while (!pq.empty()) {
		pair<int, int> now_node = pq.top().second;	//pq�� �ִ� ��� ����
		int now_cost = -pq.top().first;				//pq�� �ִ� ��� ����
		pq.pop();
		if (now_cost > dist[now_node.first][now_node.second]) continue;		//�̹� �� �ּҷ� �μ��� ������ ��� �ִٸ� �Ʒ� �ڵ� �� ����
		for (int i = 0; i < 4; i++)
		{
			int val;
			pair<int, int> next_node = make_pair(now_node.first + dx[i], now_node.second + dy[i]);
			if (next_node.first <= 0 || next_node.second <= 0 || next_node.first > n || next_node.second > m)	//���� ����� ����
				continue;
			if (arr[next_node.first][next_node.second] == 0) val = 0;				//���� �ִºκ��̸� ����� 1, �������� 0
			else val = 1;
			if (dist[now_node.first][now_node.second] + val < dist[next_node.first][next_node.second]){		//������ ���ּҺμ� ��κ��� �� �� ���ݺν����� dist �迭�� pq�� ����
				dist[next_node.first][next_node.second] = dist[now_node.first][now_node.second] + val;
				pq.push(make_pair(-dist[next_node.first][next_node.second], next_node));
			}
		}
	}
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INF;
	dijkstra(n, m);
	printf("%d\n", dist[n][m]);
	return 0;
}