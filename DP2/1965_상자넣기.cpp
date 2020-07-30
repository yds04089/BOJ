#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;


int dp[1001];
vector<int> arr;

int LIS(int n)	//LIS 알고리즘
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i]) max = dp[i];
	}
	return max;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int n1;
		scanf("%d", &n1);
		arr.push_back(n1);
		dp[i] = 1;
	}
	int ans = LIS(n);
	printf("%d\n", ans);	
	return 0;
}