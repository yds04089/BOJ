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
	for (int i = 1; i < n; i++) {		//dp[i]�� i��° ���ڸ� ������ �����κм����� �� �� �ִ�
		for (int j = 0; j < i; j++) {	//i���� �պκ� ���ڵ� ���鼭 dp[i]���� ��� �����ؼ� �ִ�� ����
			if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i])	
				dp[i] = dp[j] + arr[i];
		}
		if (dp[i] == 0)
			dp[i] = arr[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)		//dp�� �� �ִ� ã��
		ans = max(dp[i], ans);
	printf("%lld\n", ans);
	return 0;
}