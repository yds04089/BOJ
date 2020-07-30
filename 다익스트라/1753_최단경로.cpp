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
vector <pair<int, int>> arr[20001];		//<x, y, ���>
priority_queue <pair<int, int>> pq;		//<���(*-1), ���>
int dist[20001];						//�ִܰŸ� ���� �迭

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push(make_pair(0, start));		//������ push
	while (!pq.empty()) {
		int now_node, now_cost;
		now_node = pq.top().second;		//���� ���
		now_cost = -pq.top().first;	//���� �������� ���
		pq.pop();
		if (dist[now_node] < now_cost) continue;	//���� �̹� ����������� �ִܰŸ��� �ִٸ� ����
		for (int i = 0; i < arr[now_node].size(); i++) {
			int next_node, next_cost;
			next_node = arr[now_node][i].first;
			next_cost = arr[now_node][i].second;
			if (dist[next_node] > dist[now_node] + next_cost) {	//���ο� �ִܰŸ� ��Ÿ���ٸ�
				dist[next_node] = dist[now_node] + next_cost;
				pq.push(make_pair(-dist[next_node], next_node));	//����ó���ؼ� priority queue�� ����
			}
		}
	}
}

int main()
{
	int v, e, k;
	scanf("%d%d%d", &v, &e, &k);
	for (int i = 0; i <= v; i++) dist[i] = INF;		//�ִܰŸ� �迭�� ���Ѵ밪���� �ʱ�ȭ
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