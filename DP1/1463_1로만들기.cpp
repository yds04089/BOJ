#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>

using namespace std;

int dp[1000001] = {0, 0, 1};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        int minnum = 1987654321;
        if (i % 3 == 0) {
            minnum = min(dp[i / 3], dp[i - 1]) + 1;
        }
        if (i % 2 == 0) {
            minnum = min(dp[i / 2] + 1, min(minnum, dp[i - 1] + 1));
        }
        else if (i % 2 != 0 && i % 3 != 0) {
            minnum = dp[i - 1] + 1;
        }
        dp[i] = minnum;
    }
    printf("%d\n", dp[n]);
    return 0;
}