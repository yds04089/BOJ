#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int dp[1010][1010];

int main()
{
	int n; 
	scanf("%d", &n);
	for (int i=0; i<=n+9; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j)
				dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];	//점화식
				dp[i][j] %= 10007;
			}
		}
	int ans = dp[n + 9][9];	//중복조합 10Hn을 구해야해서 조합으로 나타내면 (9+n)C9가 됨
	printf("%d\n", ans);
	return 0;
}