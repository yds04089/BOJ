#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int dp[2][100001] = {};
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &dp[i][j]);
		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[0][j - 1], dp[0][j] + dp[1][j - 1]);	//Á¡È­½Ä
			dp[1][j] = max(dp[1][j - 1], dp[1][j] + dp[0][j - 1]);
		}
		printf("%d\n", max(dp[0][n], dp[1][n]));
	}
	return 0;
}