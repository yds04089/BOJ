#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
#define INF 987654321
int arr[401][401];
int dist[401][401];

void floyd_warshall(int n)
{
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j = 1; j <= n; j++) 
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;		//�迭 INF�� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;				//�밢���� 0���� �ʱ�ȭ
	for (int i = 0; i < k; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		dist[from][to] = 1;
	}
	floyd_warshall(n);		//�÷��̵�ͼ�
	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		if (dist[n1][n2] != INF) printf("-1\n");	//n1���� n2�� ��� �ִ°��
		else if (dist[n2][n1] != INF) printf("1\n");	//n2���� n1�� ��� �ִ°��
		else printf("0\n");			//��� ���� ���
	}
	return 0;
}