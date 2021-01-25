#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>

using namespace std;

int dp[10001];
int arr[10001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i = 4; i <= n; i++) {
        dp[i] = max(max(dp[i - 3], dp[i - 4]) + arr[i - 1] + arr[i], max(dp[i - 2], dp[i - 3]) + arr[i]);
    }
    int ans = max(dp[n - 1], dp[n]);
    printf("%d\n", ans);
    return 0;
}