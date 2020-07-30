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

int arr[1000][1000];
int visit[1000][1000][2];				//���� �հ� �� ���� �׳� �� ����� �湮�� �ٸ��� ���� ([][][0]�� ���ȶհ� �� ���,
queue<pair<pair<int, int>, pair<int, int>>> q;											  //[][][1]�� �� �հ� �� ���)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans;

void bfs(int n, int m)
{
	ans = -1;							//�⺻������ -1 ����
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));	
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> now = q.front().first;
		int cnt = q.front().second.first;
		int change = q.front().second.second;
		if (now.first == n - 1 && now.second == m - 1)		//������ ��忡 �����ϸ� �� �����ϰ� ����
		{
			ans = q.front().second.first;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)							//�� ���� ���� BFS
		{
			pair<int, int> next = make_pair(now.first + dx[i], now.second + dy[i]);
			
			if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)	//���� ����� ����
				continue;
			if (arr[next.first][next.second] == 0 && visit[next.first][next.second][change] == 0)	//�� 0�� ���� �� ���
			{
				visit[next.first][next.second][change] = 1;						//�̹� �� �հ� �Դ��� ���ο� ���� visit�� 1�� �ٲ�
				q.push(make_pair(next, make_pair(cnt + 1, change)));
			}
			else if (arr[next.first][next.second] == 1 && visit[next.first][next.second][1] == 0)	//�� 1�� ���� �� ���
			{
				if (change == 0)						//���� �� �ȶհ� �� ���
				{
					visit[next.first][next.second][1] = 1;			//�� �հ� �� visit �� 1�� �ٲ�
					q.push(make_pair(next, make_pair(cnt + 1, change + 1)));
				}
			}
		}
	}
}

int main()
{
	int n, m, realans = -1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	bfs(n, m);
	printf("%d\n", ans);
	return 0;
}