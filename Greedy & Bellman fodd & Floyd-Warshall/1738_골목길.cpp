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
vector<pair<int, int>> arr[103];
int dist[103];
int prev_[103];

int bellman_fodd(int n)		//�������� �˰���
{
	for (int k = 1; k <= 1000*n; k++) {	//����Ŭ�� ���� 
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				if (dist[from] == -INF) break;		//������� -INF�� ����
				if (dist[to] < dist[from] + arr[i][j].second) {	//�ִܰŸ� ������Ʈ
					if (k >= n && to == n)		//n��°�̻󿡼� ������Ʈ�� �Ǹ� ����Ŭ �����
					{							//����Ŭ�� n�� �����ϰ� ������ 1 ����
						return 1;
					}
					dist[to] = dist[from] + arr[i][j].second;
					prev_[to] = from;			//prev�迭�� �������� ����
				}
			}
		}
	}
	return 0;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		dist[i] = -INF;
	for (int i = 0; i < m; i++) {	
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	dist[1] = 0;	
	int check = bellman_fodd(n);
	if (check == 1 || dist[n] == -INF) {	//����Ŭ�� n���� ���ų� n���� �ִܰŸ� ���°��
		printf("-1\n");
		return 0;
	}
	int idx = n;
	vector<int> ans;		//���������� ��������� �Ųٷ� ����, �����ϴ� �迭
	while (1) {
		ans.push_back(idx);
		if (idx == 1) {		//��������� �� �����Ǹ� ����
			break;
		}
		int tmp = prev_[idx];
		idx = tmp;
	}
	for (int i = ans.size() - 1; i >= 0; i--)	//�������� ans�迭 ���
		printf("%d ", ans[i]);
	return 0;
}