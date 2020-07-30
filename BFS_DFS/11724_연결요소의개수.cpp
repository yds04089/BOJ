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

vector<int> arr[1001];
int visit[1001] = {};
int cnt;

void dfs(int v)
{
	visit[v] = 1;
	for (int i = 0; i < arr[v].size(); i++)
	{
		if (visit[arr[v][i]] == 0)
		{
			dfs(arr[v][i]);		
			cnt++;				//���ο� dfs�� �����Ҷ����� cnt����
		}						//������ ������ ��� ��� ������ cnt�� ��Ű��Ե�
	}
}

int main()
{
	int n, m, ans;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}
	for (int i = 1; i <= n; i++)
		dfs(i);
	ans = n - cnt;			//cnt���� ������ ������ ���� ������ ���Ƿ�
	printf("%d\n",ans);		//n - cnt�� �ϸ� �� dfs�� ������ ����(�������� ����)�� ����
	return 0;
}

/* for (int i = 1; i <= N; i++)
                 if (!visited[i])		//�̷������� ������ ã�°� �ξ� ����
                 {
                         dfs(i);
                         cnt++;
                 }*/