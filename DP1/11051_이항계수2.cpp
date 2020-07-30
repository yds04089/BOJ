#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;
int dp[1001][1001];	

int sol(int n, int k)	//탑다운 방식
{
	if (n == k || k == 0) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	else if (dp[n][k] != 0)
		return dp[n][k];
	dp[n][k] = sol(n - 1, k - 1) + sol(n - 1, k);	//메모이제이션
	dp[n][k] %= 10007;
	return dp[n][k];
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = sol(n, k);
	printf("%d\n", ans);
	return 0;
}