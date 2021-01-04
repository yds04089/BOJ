#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;
long long dp[101][100001];	
int arr[101][2];	//무게, 가치 저장하는 배열

void knapsack(int n, int k)
{
	for (int i = 1; i <= n; i++) {	//i는 물건의 index
		for (int j = 1; j <= k; j++) {	//j는 무게의 최대 허용 용량
			if (arr[i][0] > j)	//전체 가방용량보다 무게가 큰 경우
				dp[i][j] = dp[i - 1][j];
			else {		//i번째 물건을 넣기 전의 가치와 i번째 물건의 무게를 제외한 가치에 i번째 물건의 가치 더한 값 비교
				dp[i][j] = max(dp[i - 1][j - arr[i][0]] + arr[i][1], dp[i-1][j]);
			}
		}
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	knapsack(n, k);
	printf("%lld\n", dp[n][k]);
	return 0;
}