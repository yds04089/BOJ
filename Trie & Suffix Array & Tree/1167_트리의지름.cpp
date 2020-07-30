#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
#include <string>
#include<queue>
using namespace std;

int visit[100001];
vector<pair<int, int>> arr[100001];
int dist[100001];
queue <int> q;
int maxdist;
int faridx;

void bfs(int n)
{
	q.push(n);
	visit[n] = 1;
	dist[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			if (visit[arr[now][i].first] == 0) {
				q.push(arr[now][i].first);
				visit[arr[now][i].first] = 1;
				dist[arr[now][i].first] = arr[now][i].second + dist[now];

				if (dist[arr[now][i].first] > maxdist) {	//최대길이이면 maxdist, faridx 바꿔줌
					maxdist = dist[arr[now][i].first];
					faridx = arr[now][i].first;
				}
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		int cnt = 0;
		int node, idx;
		while (1) {
			cnt++;
			int tmp;
			scanf("%d", &tmp);
			if (tmp == -1)
				break;
			if (cnt == 1) 
				node = tmp;
			else {
				if (cnt % 2 == 0) {
					idx = tmp;
				}
				else {
					arr[node].push_back(make_pair(idx, tmp));
				}
			}
		}
	}
	bfs(1);
	memset(dist, 0, sizeof(dist));	//거리와 visit 배열 초기화
	memset(visit, 0, sizeof(visit));
	bfs(faridx);
	printf("%d\n", maxdist);
	return 0;
}