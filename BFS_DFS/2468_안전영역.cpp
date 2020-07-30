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

int arr[102][102];
int visit[102][102] = {};
queue<pair<int, int>> q;


int makeGroup(int wat, int n)           //ȫ���� ���� ���̰� �־����� �� �������� ������ ���� ��ȯ
{
	int cnt = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] > wat)
			{
				if (visit[i][j] == 0)
				{
					q.push(make_pair(i,j));
					while (!q.empty())
					{
						pair<int, int> front;								//pair�Ἥ queue�ȿ� ��ġ �־���
						front = q.front();
						pair<int, int> r_front = make_pair(front.first + 1, front.second);  //�����ʺκ�
						pair<int, int> d_front = make_pair(front.first, front.second + 1);	//�Ʒ��κ�
						pair<int, int> l_front = make_pair(front.first - 1, front.second);	//���ʺκ�
						pair<int, int> u_front = make_pair(front.first, front.second - 1);	//���κ�
						q.pop();
						if (arr[r_front.first][r_front.second] > wat && visit[r_front.first][r_front.second] == 0)
						{
							q.push(r_front);
							visit[r_front.first][r_front.second] = 1;
						}
						if (arr[d_front.first][d_front.second] > wat && visit[d_front.first][d_front.second] == 0)
						{
							q.push(d_front);
							visit[d_front.first][d_front.second] = 1;
						}
						if (arr[l_front.first][l_front.second] > wat&& visit[l_front.first][l_front.second] == 0)
						{
							q.push(l_front);
							visit[l_front.first][l_front.second] = 1;
						}
						if (arr[u_front.first][u_front.second] > wat&& visit[u_front.first][u_front.second] == 0)
						{
							q.push(u_front);
							visit[u_front.first][u_front.second] = 1;
						}
					}
					cnt++;
				}
			}
			visit[i][j] = 1;
		}
	}
	return cnt;
}

int main()
{
	int n, min = 101, max = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (min > arr[i][j]) min = arr[i][j];		//�� �κ��� ������ �ִ񰪰� �ּڰ� ã����
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	int ans = 0;
	for (int i = min-1; i <= max; i++)
	{
		int num = makeGroup(i, n);
		if (ans < num) ans = num;
	}
	printf("%d\n", ans);
	return 0;
}