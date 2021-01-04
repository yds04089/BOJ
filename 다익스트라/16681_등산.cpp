#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

const long long INF = LLONG_MAX;			//long long�� �ִ�
vector <pair<int, long long>> arr[100001];		//<���, ���>
priority_queue <pair<long long, int>> pq;	//<���(*-1), ���>
long long dist1[100001];			//�ִܰŸ� ���� �迭 
long long dist2[100001];
int height[100001];			//��������		

int is_up(int h1, int h2)	//�ö󰡴� �������� �Ǵ�
{
	if (height[h1] < height[h2])
		return 1;
	else
		return 0;
}

void dijkstra1()		//1���� ����ϴ� ���ͽ�Ʈ��
{

	dist1[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		long long now_cost = -pq.top().first;
		pq.pop();
		if (dist1[now] < now_cost) continue;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			long long next_cost = arr[now][i].second;
			if (is_up(now, next) == 0) continue;
			if (dist1[next] > dist1[now] + next_cost) {
				dist1[next] = dist1[now] + next_cost;
				pq.push(make_pair(-dist1[next], next));
			}
		}
	}
}

void dijkstra2(int n)		//n���� ����ϴ� ���ͽ�Ʈ��
{

	dist2[n] = 0;
	pq.push(make_pair(0, n));
	while (!pq.empty()) {
		int now = pq.top().second;
		long long now_cost = -pq.top().first;
		pq.pop();
		if (dist2[now] < now_cost) continue;
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			long long next_cost = arr[now][i].second;
			if (is_up(now, next) == 0) continue;
			if (dist2[next] > dist2[now] + next_cost) {
				dist2[next] = dist2[now] + next_cost;
				pq.push(make_pair(-dist2[next], next));
			}
		}
	}
}

int main()
{
	int n, m, d, e;
	scanf("%d%d%d%d", &n, &m, &d, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &height[i]);
	for (int i = 0; i < m; i++) {
		int from, to, distance;
		scanf("%d%d%d", &from, &to, &distance);
		arr[from].push_back(make_pair(to, distance));
		arr[to].push_back(make_pair(from, distance));
	}
	for (int i = 0; i <= n; i++) {
		dist1[i] = INF;
		dist2[i] = INF;
	}
	dijkstra1();
	dijkstra2(n);
	int check = 0;
	long long max = -INF;
	for (int i = 2; i < n; i++) {
		if (dist1[i] != INF && dist2[i] != INF) {		//1������ n���� �� �� ����(i���)�� ������ ��츸 ���
			long long value = (long long)e * height[i] - d * dist1[i] - d * dist2[i];
			check++;
			if (max < value)
				max = value;
		}
	}
	if (check == 0)					//1������ n���� �Ѵ� �̾��� ���� ���� ���
		printf("Impossible\n");
	else
		printf("%lld\n", max);
	return 0;
}