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
		arr[n2].push_back(n1);				//방향성이 있음
	}
	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end());		//오름차순으로 보랴고 정렬
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;							//cnt 초기화
		int ans;
		for (int j = 0; j <= 10000; j++)			//visit 초기화
			visit[j]=0;
		dfs(i);								//dfs를 통해 해킹할수있는 컴퓨터 개수 알아냄
		ans = cnt;
		if (ans > max)			
		{
			max = ans;	
			com_node.clear();					//최댓값이 바뀌면 기존의 벡터를 초기화해줌
			com_node.push_back(i);				//초기화 후 새로운 최댓값 삽입
		}
		else if (ans == max)
			com_node.push_back(i);				//새로운 최댓값과 값이 같아도 벡터에 삽입
	}
	for (int i = 0; i < com_node.size(); i++)
		printf("%d ", com_node[i]);
	return 0;
}