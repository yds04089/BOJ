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
void sol(int v)		//플로이드와샬
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
			dist[i][j] = INF;				//dist배열을 INF로 초기화
	for (int i = 1; i <= v; i++) dist[i][i] = 0;	//대각선부분만 0으로 초기화
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		dist[from][to] = cost;
	}
	sol(v);			//플로이드와샬
	int ans = INF;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;	//대각선부분은 무시
			if (dist[i][j] < INF && dist[j][i] < INF)	//양방향 다 존재하면
				ans = min(ans, dist[i][j] + dist[j][i]);
		}
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}