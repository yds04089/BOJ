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
int visit[1000][1000][2];				//벽을 뚫고 온 경우와 그냥 온 경우의 방문을 다르게 구분 ([][][0]은 벽안뚫고 온 경우,
queue<pair<pair<int, int>, pair<int, int>>> q;											  //[][][1]은 벽 뚫고 온 경우)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans;

void bfs(int n, int m)
{
	ans = -1;							//기본값으로 -1 설정
	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));	
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> now = q.front().first;
		int cnt = q.front().second.first;
		int change = q.front().second.second;
		if (now.first == n - 1 && now.second == m - 1)		//마지막 노드에 도착하면 값 저장하고 끝냄
		{
			ans = q.front().second.first;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)							//네 방향 노드로 BFS
		{
			pair<int, int> next = make_pair(now.first + dx[i], now.second + dy[i]);
			
			if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)	//범위 벗어나면 무시
				continue;
			if (arr[next.first][next.second] == 0 && visit[next.first][next.second][change] == 0)	//값 0인 곳에 온 경우
			{
				visit[next.first][next.second][change] = 1;						//이미 벽 뚫고 왔는지 여부에 따라 visit값 1로 바꿈
				q.push(make_pair(next, make_pair(cnt + 1, change)));
			}
			else if (arr[next.first][next.second] == 1 && visit[next.first][next.second][1] == 0)	//값 1인 곳에 온 경우
			{
				if (change == 0)						//아직 벽 안뚫고 온 경우
				{
					visit[next.first][next.second][1] = 1;			//벽 뚫고 온 visit 값 1로 바꿈
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