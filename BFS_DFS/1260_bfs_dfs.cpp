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

void dfs(int v)     //stack으로 짜는거는 좀 어려움
{
	printf("%d ", v);
	vd[v] = true;
	for (int i = 0; i < arr[v].size(); i++)   //인접한 노드들 확인
	{
		if (vd[arr[v][i]] == false)   //방문 안했으면 재귀
			dfs(arr[v][i]);
	}
}

void bfs(int v)
{
	q.push(v);      //시작점 q에 push
	vb[v] = true;
	while (!q.empty())
	{
		int front = q.front();  //현재 노드값
		q.pop();                //방문한 노드는 큐에서 pop
		for (int i = 0; i < arr[front].size(); i++)
		{
			if (vb[arr[front][i]] == false)    //인접 노드중 방문 안한 것들
			{
				q.push(arr[front][i]);  //방문할 노드 q에 push
				vb[arr[front][i]] = true;   //방문체크
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
		//벡터 내부 중복제거 (하기 전에 정렬해야함)
	}
	dfs(v);
	printf("\n");
	bfs(v);

	
	return 0;
}