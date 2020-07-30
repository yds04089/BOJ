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

vector<int> arr[101001];
int tmparr[1001][1001];
queue<pair<int, int>> q;
int visit[101001];

void bfs(int n)
{
	int cnt = 1;
	q.push(make_pair(1, cnt));
	visit[1] = 1;
	while (!q.empty())
	{
		int now = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (now == n)
		{
			printf("%d\n", cnt);
			return;
		}
		for (int i = 0; i < arr[now].size(); i++)
		{
			int next = arr[now][i];
			if (visit[next] == 0)
			{
				visit[next] = 1;
				if (next > n)			//���� ������Ʃ���̸� cnt�״��
					q.push(make_pair(next, cnt));
				else					//���� ���� ���̸� cnt+1
					q.push(make_pair(next, cnt + 1));	
			}
		}
	}
	printf("-1\n");
}

int main()
{
	int n, k, m;
	vector <int> ::iterator iter;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &tmparr[i][j]);
			arr[n + i].push_back(tmparr[i][j]);		//������Ʃ�꿡 ������ �̾���
		}											//���� �̿��ؼ� bfs���������ϸ� �ð��ʰ�/�޸��ʰ� ��
	}
	for (int i = n + 1; i <= n + m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int tmp = arr[i][j];
			arr[tmp].push_back(i);					//���� ������Ʃ�� �̾���
		}
	}

	bfs(n);
	return 0;
}