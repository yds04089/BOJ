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
vector <pair<int, int>> arr[50001];		//<���, ���>
priority_queue <pair<pair<long long, int>, int>> pq;	//<���(*-1), ���>, �װ��� ������>
long long dist[50001][2];			//�ִܰŸ� ���� �迭(�װ���X, �װ���O) 
									//���� ũ�Ƿ� long long ���
void dijkstra(int start)
{
	pq.push(make_pair(make_pair(0, start), 0));
	dist[start][0] = 0;
	while (!pq.empty()) {
		int now = pq.top().first.second;
		long long now_cost = -pq.top().first.first;
		int isFlight = pq.top().second;		//�װ��� ����� ����
		pq.pop();
		if (dist[now][isFlight] < now_cost) continue;	//�̹� �ִܰŸ� ������ ����
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			long long next_cost = arr[now][i].second;
			if (next_cost == 0 && isFlight == 1) continue;	//�̹� �װ��� ��µ� �� �װ��� ���� ��� ����
			if (next_cost == 0 && isFlight == 0) {			//���� �װ��� �Ƚ�µ� �װ��� ���� ���
				isFlight = 1;
				if (dist[next][isFlight] > next_cost + dist[now][0]) {
					dist[next][isFlight] = next_cost + dist[now][0];
					pq.push(make_pair(make_pair(-dist[next][isFlight], next), isFlight));
				}
			}
			else {							//�Ϲ� ���η� ���� ���
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
	for (int i = 0; i < m; i++) {		//�Ϲ� ���� �߰�
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
		arr[to].push_back(make_pair(from, cost));
	}
	for (int i = 0; i < f; i++) {		//�װ��� �߰�
		int u, v;
		scanf("%d%d", &u, &v);
		arr[u].push_back(make_pair(v, 0));
	}
	for (int i = 0; i <= n; i++) {		//�ִܰŸ� �ʱ�ȭ
		dist[i][0] = INF; 
		dist[i][1] = INF;
	}
	dijkstra(s);
	printf("%lld\n", min(dist[t][0], dist[t][1]));
	return 0;
}