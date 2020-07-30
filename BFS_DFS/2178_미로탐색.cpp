#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
#include<utility>
using namespace std;

int arr[100][100];
int visit[100][100];
queue <pair <pair<int, int>, int>> q;			//<�ڸ���, �ڸ���, ī��Ʈ>
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(int n, int m)
{
	q.push(make_pair(make_pair(0, 0), 1));
	while (!q.empty())
	{
		pair<int, int> now = q.front().first; 
		int now_cnt = q.front().second;
		if (now.first == n - 1 && now.second == m - 1)			//�� ������ ĭ�� �����ϸ� ��� �� break
		{
			printf("%d", now_cnt);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (now.first + dx[i] < 0 || now.second + dy[i] < 0 || now.first + dx[i] >= n || now.second + dy[i] >= m)
				continue;															//���� ���� ������ �Ѿ�� ����
			pair<int, int> next;
			next = make_pair(now.first + dx[i], now.second + dy[i]);				//������ �� ���
			if (arr[next.first][next.second] == 1 && visit[next.first][next.second] == 0)	//ĭ�� ���� 1�̰� �湮 ��������
			{																				//ť�� ���� ���� ī��Ʈ+1�� �־���
				q.push(make_pair(next, now_cnt+1));
				visit[next.first][next.second] = 1;									//�湮 üũ
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	bfs(n, m);
	return 0;
}