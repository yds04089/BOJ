#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>

using namespace std;

int dp[1500001];
int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t, p;
        scanf("%d %d", &t, &p);
        ans = max(ans, dp[i]);
        if (i + t > n + 1) 
            continue;
        dp[i + t] = max(ans + p, dp[i + t]);
    }
    ans = max(ans, dp[n+1]);
    printf("%d\n", ans);
    return 0;
}