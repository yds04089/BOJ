#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 923456789
vector<pair<int, int>> arr[501];
int dist[501];

int bellman_fodd(int n)		//�������� �˰���
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				if (dist[from] == INF) break;		//������� INF�� ����
				if (dist[to] > dist[from] + arr[i][j].second) {	//�ִܰŸ� ������Ʈ
					dist[to] = dist[from] + arr[i][j].second;
					if (k == n)		//n��°���� ������Ʈ�� �Ǹ� ������ ���� ����Ŭ �����
						return 1;
				}
			}
		}
	}
	return 0;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	for (int i = 1; i <= n; i++)
			dist[i] = INF;
	dist[1] = 0;
	int check = bellman_fodd(n);	
	if (check == 1) {		//����Ŭ �������� -1����ϰ� ����
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= n; i++){
		if (dist[i] == INF)	//Ư�� ������ �ִܰŸ� ������ -1 ���
			dist[i] = -1;
		printf("%d\n", dist[i]);
	}
	return 0;
}