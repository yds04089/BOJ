#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<deque>
using namespace std;

#define maxnum 500001

int par[maxnum][21], visit[maxnum], d[maxnum], dist[maxnum];
vector<vector<pair<int, int>>> tree;

void dfs(int node, int depth, int dis) {
    visit[node] = true;
    d[node] = depth;
    dist[node] = dis;
    for (auto there : tree[node]) {
        if (visit[there.first])
            continue;
        par[there.first][0] = node;
        dfs(there.first, depth + 1, dis + there.second);
    }
}

int lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i))
            y = par[y][i];
    }
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main()
{
    int n, m;
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int tmp1, tmp2, tmp3;
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        tree[tmp1].push_back({tmp2, tmp3});
        tree[tmp2].push_back({tmp1, tmp3});
    }
    dfs(1, 0, 0);
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        int res = lca(tmp1, tmp2);
        printf("%d\n", dist[tmp1] + dist[tmp2] - 2 * dist[res]);
    }
    return 0;
}