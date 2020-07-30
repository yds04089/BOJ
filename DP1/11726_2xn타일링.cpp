#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<string.h>
#include<limits.h>
using namespace std;

int dp[1001];

int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];	//dp 점화식
		dp[i] %= 10007;		//intmax 안넘게 매번 나눠줌
	}
	printf("%d\n", dp[n]);
	return 0;
}