#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 100000

int arr[401][401];
int dist[401][401];
void sol(int v)		//�÷��̵�ͼ�
{
	for (int k=1; k<=v;k++)
		for (int i=1; i<=v; i++)
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dist[i][j] = INF;				//dist�迭�� INF�� �ʱ�ȭ
	for (int i = 1; i <= v; i++) dist[i][i] = 0;	//�밢���κи� 0���� �ʱ�ȭ
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		dist[from][to] = cost;
	}
	sol(v);			//�÷��̵�ͼ�
	int ans = INF;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;	//�밢���κ��� ����
			if (dist[i][j] < INF && dist[j][i] < INF)	//����� �� �����ϸ�
				ans = min(ans, dist[i][j] + dist[j][i]);
		}
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}