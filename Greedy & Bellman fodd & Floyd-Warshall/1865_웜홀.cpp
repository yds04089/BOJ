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
vector<pair<int, int>> arr[503];
int dist[503];

int bellman_fodd(int n)		//�������� �˰���
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				//if (dist[from] == INF) break;		//������� INF���� �����ϸ� �ȵ� (������� ����� �𸣱� ����)
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
	int tc;
	scanf("%d", &tc);
	for (int z = 0; z < tc; z++) {
		int n, m, w;
		scanf("%d%d%d", &n, &m, &w);
		for (int i = 1; i <= n; i++) {
			arr[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < m; i++) {	//���� �Է¹���
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			arr[from].push_back(make_pair(to, cost));
			arr[to].push_back(make_pair(from, cost));
		}
		for (int i = 0; i < w; i++) {	//��Ȧ �Է¹���
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			arr[from].push_back(make_pair(to, -cost));
		}
		dist[1] = 0;	//���Ƿ� ������� 1�� ������ ��� �ص� �������
		int check = bellman_fodd(n);
		if (check == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}