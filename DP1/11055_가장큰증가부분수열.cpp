#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

long long dp[1010];
int arr[1001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {		//dp[i]는 i번째 숫자를 포함한 증가부분수열의 합 중 최댓값
		for (int j = 0; j < i; j++) {	//i보다 앞부분 숫자들 보면서 dp[i]값을 계속 갱신해서 최대로 만듬
			if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i])	
				dp[i] = dp[j] + arr[i];
		}
		if (dp[i] == 0)
			dp[i] = arr[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)		//dp값 중 최댓값 찾기
		ans = max(dp[i], ans);
	printf("%lld\n", ans);
	return 0;
}