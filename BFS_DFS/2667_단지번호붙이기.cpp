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

int visit[26][26];
int arr[26][26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> house;
int house_num;

void dfs(pair<int, int> v, int n)
{
	visit[v.first][v.second] = 1;
	house_num++;					//house_num ����
	for (int i=0;i<4;i++)			//4���⿡�� dfs
	{
		if (v.first+dx[i]<0 || v.second+dy[i]<0 || v.first+dx[i]>=n || v.second+dy[i]>=n)
			continue;					//���� ���� ���̸� ����
		pair<int, int> next= make_pair(v.first+dx[i], v.second+dy[i]);
		if (arr[next.first][next.second]==1 && visit[next.first][next.second]==0)
		{
			dfs(next, n);
		}
	}
}

int main()
{
	int n;
	int cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);	//�پ��ִ� ���ڵ��̶� �̷����ؾ� �����ϳ��� �޾���
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (visit[i][j]==0 && arr[i][j]==1)		//���� �湮���� �ʾҰ� ���� 1�ΰ͸� �湮
			{
				house_num=0;						//���ο� dfs���� hous_num �ʱ�ȭ
				dfs(make_pair(i, j), n);
				house.push_back(house_num);		//house�迭�� house_num�� ����
				cnt++;							//����� ������ ���� �ϳ� ����
			}
		}
	}

	sort(house.begin(), house.end());		//�������� ����
	printf("%d\n", cnt);
	for (int i = 0; i < house.size(); i++)
		printf("%d\n", house[i]);
	return 0;
}