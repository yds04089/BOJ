#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 987654321
vector<pair<int, int>> arr[103];
int dist[103];
int prev_[103];

int bellman_fodd(int n)		//벨만포드 알고리즘
{
	for (int k = 1; k <= 1000*n; k++) {	//사이클을 도는 
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				int from = i;
				int to = arr[i][j].first;
				if (dist[from] == -INF) break;		//출발점이 -INF면 무시
				if (dist[to] < dist[from] + arr[i][j].second) {	//최단거리 업데이트
					if (k >= n && to == n)		//n번째이상에서 업데이트가 되면 사이클 생긴것
					{							//사이클이 n을 포함하고 있으면 1 리턴
						return 1;
					}
					dist[to] = dist[from] + arr[i][j].second;
					prev_[to] = from;			//prev배열로 이전값들 저장
				}
			}
		}
	}
	return 0;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		dist[i] = -INF;
	for (int i = 0; i < m; i++) {	
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		arr[from].push_back(make_pair(to, cost));
	}
	dist[1] = 0;	
	int check = bellman_fodd(n);
	if (check == 1 || dist[n] == -INF) {	//사이클이 n까지 가거나 n까지 최단거리 없는경우
		printf("-1\n");
		return 0;
	}
	int idx = n;
	vector<int> ans;		//도착점부터 출발점까지 거꾸로 추적, 저장하는 배열
	while (1) {
		ans.push_back(idx);
		if (idx == 1) {		//출발점까지 다 추적되면 종료
			break;
		}
		int tmp = prev_[idx];
		idx = tmp;
	}
	for (int i = ans.size() - 1; i >= 0; i--)	//역순으로 ans배열 출력
		printf("%d ", ans[i]);
	return 0;
}