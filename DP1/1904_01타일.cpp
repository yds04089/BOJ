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

int dp[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];	//dp의 점화식
		dp[i] %= 15746;		//중간에 intmax값 초과하게 되므로 나눠줌
	}
	printf("%d", dp[n]);
	return 0;
}