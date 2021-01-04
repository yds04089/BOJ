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

int visit[1000001];
queue<pair<int, int>> q;		//<위치, 카운트>인 큐

void bfs(int f, int s, int g, int u, int d)
{
	visit[s] = 1;
	int cnt = 0;
	int ud[2] = { u, -d };		//위, 아래로 몇칸씩인지 저장
	q.push(make_pair(s, cnt));
	while (!q.empty())
	{
		int now = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (now == g)			//도착점에 가면 카운트 출력 후 종료
		{
			printf("%d\n", cnt);
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			int next = now + ud[i];
			if (next > f || next <= 0)	//범위 벗어나면 무시
				continue;
			if (visit[next] == 0)		
			{
				q.push(make_pair(next, cnt+1));		//방문안한 층의 위치와 카운트+1을 큐에 넣음
				visit[next] = 1;
			}
		}
	}
	printf("use the stairs\n");
}

int main()
{
	int f, s, g, u, d;
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	bfs(f, s, g, u, d);
	return 0;
}