#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> tree[100001];
int size_cnt[100001];
int vi[100001];

int dfs(int num) {
    if (size_cnt[num] != 0)
        return size_cnt[num];
    vi[num] = 1;
    int size = 1;
    for (int i = 0; i < tree[num].size(); i++) {
        int next = tree[num][i];
        if (vi[next] == 1)
            continue;
        size += dfs(next);
    }
    size_cnt[num] = size;
    return size;
}

int main()
{
    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    size_cnt[r] = dfs(r);
    int query;
    for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        printf("%d\n", size_cnt[query]);
    }
    return 0;
}