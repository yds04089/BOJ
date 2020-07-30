#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;
long long dp[100];	//intmax보다 커지기 때문에 longlong 사용
int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];	//점화식
	printf("%lld\n", dp[n]);
	return 0;
}