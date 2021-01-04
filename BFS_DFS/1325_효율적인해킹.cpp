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

vector<int> com_node;
vector<int> arr[10001];
int visit[10001];
int cnt;

void dfs(int v)
{
	visit[v] = 1;
	for (int i = 0; i < arr[v].size(); i++)
	{
		if (visit[arr[v][i]] == 0)
			dfs(arr[v][i]);
	}
	cnt++;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		arr[n2].push_back(n1);				//���⼺�� ����
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end());		//������������ ������ ����
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;							//cnt �ʱ�ȭ
		int ans;
		for (int j = 0; j <= 10000; j++)			//visit �ʱ�ȭ
			visit[j]=0;
		dfs(i);								//dfs�� ���� ��ŷ�Ҽ��ִ� ��ǻ�� ���� �˾Ƴ�
		ans = cnt;
		if (ans > max)			
		{
			max = ans;	
			com_node.clear();					//�ִ��� �ٲ�� ������ ���͸� �ʱ�ȭ����
			com_node.push_back(i);				//�ʱ�ȭ �� ���ο� �ִ� ����
		}
		else if (ans == max)
			com_node.push_back(i);				//���ο� �ִ񰪰� ���� ���Ƶ� ���Ϳ� ����
	}
	for (int i = 0; i < com_node.size(); i++)
		printf("%d ", com_node[i]);
	return 0;
}