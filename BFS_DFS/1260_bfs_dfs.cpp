#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr[1001];
queue <int> q;
bool vd[1001];
bool vb[1001];

void dfs(int v)     //stack���� ¥�°Ŵ� �� �����
{
	printf("%d ", v);
	vd[v] = true;
	for (int i = 0; i < arr[v].size(); i++)   //������ ���� Ȯ��
	{
		if (vd[arr[v][i]] == false)   //�湮 �������� ���
			dfs(arr[v][i]);
	}
}

void bfs(int v)
{
	q.push(v);      //������ q�� push
	vb[v] = true;
	while (!q.empty())
	{
		int front = q.front();  //���� ��尪
		q.pop();                //�湮�� ���� ť���� pop
		for (int i = 0; i < arr[front].size(); i++)
		{
			if (vb[arr[front][i]] == false)    //���� ����� �湮 ���� �͵�
			{
				q.push(arr[front][i]);  //�湮�� ��� q�� push
				vb[arr[front][i]] = true;   //�湮üũ
			}
		}
		printf("%d ", front);
	}
}

int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i =1; i <= m; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}
	for (int i = 0; i < n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
		arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
		//���� ���� �ߺ����� (�ϱ� ���� �����ؾ���)
	}
	dfs(v);
	printf("\n");
	bfs(v);

	
	return 0;
}