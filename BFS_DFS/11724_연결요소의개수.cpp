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
			cnt++;				//새로운 dfs로 접근할때마다 cnt증가
		}						//정점을 제외한 모든 노드 개수가 cnt에 들거가게됨
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
	ans = n - cnt;			//cnt에는 정점을 제외한 노드들 개수가 들어가므로
	printf("%d\n",ans);		//n - cnt를 하면 각 dfs의 정점의 개수(연결요소의 개수)가 나옴
	return 0;
}

/* for (int i = 1; i <= N; i++)
                 if (!visited[i])		//이런식으로 연결요소 찾는게 훨씬 쉬움
                 {
                         dfs(i);
                         cnt++;
                 }*/