#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;
int findroot[10001];
pair<int, int> tree[10001];
int low[10001];
int high[10001];
int nodeidx;

void dfs(int n, int cnt)
{
	if (tree[n].first > 0)
		dfs(tree[n].first, cnt + 1);
	low[cnt] = min(low[cnt], nodeidx);
	high[cnt] = max(high[cnt], nodeidx);
	nodeidx++;
	if (tree[n].second > 0)
		dfs(tree[n].second, cnt + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int n1, n2, n3;
		scanf("%d %d %d", &n1, &n2, &n3);
		findroot[n1]++;
		if (n2 != -1)
			findroot[n2]++;
		if (n3 != -1)
			findroot[n3]++;
		tree[n1].first = n2;
		tree[n1].second = n3;
	}
	int root=1;
	for (int i = 1; i <= n; i++) {
		low[i] = 987654321;
		if (findroot[i] == 1)
			root = i;
	}
	nodeidx = 1;
	dfs(root, 1);
	int ans = 0;
	int lev = 1;
	for (int i = 1; i <= n; i++) {
		int tmp = high[i] - low[i] + 1;
		if (tmp > ans) {
			ans = tmp;
			lev = i;
		}
	}
	printf("%d %d\n", lev, ans);
	return 0;
}