#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

vector<int> tree[1000001];
int dp[1000001][2];

int solve(int now, int prev, int isEA) {
    if (dp[now][isEA] != -1)
        return dp[now][isEA];
    int cnt = 0;
    for (int i = 0; i < tree[now].size(); i++) {
        int next = tree[now][i];
        if (next == prev)
            continue;
        if (isEA == 0)         //얼리어답터가 아닌 경우
            cnt += solve(next, now, 1) + 1;
        else                    //얼리어답터인 경우
            cnt += min(solve(next, now, 0), solve(next, now, 1) + 1);
    }
    dp[now][isEA] = cnt;
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int ans = min(solve(1, -1, 0), solve(1, -1, 1) + 1);
    printf("%d\n", ans);
    return 0;
}