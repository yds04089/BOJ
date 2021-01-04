#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;
long long dp[101][100001];	
int arr[101][2];	//����, ��ġ �����ϴ� �迭

void knapsack(int n, int k)
{
	for (int i = 1; i <= n; i++) {	//i�� ������ index
		for (int j = 1; j <= k; j++) {	//j�� ������ �ִ� ��� �뷮
			if (arr[i][0] > j)	//��ü ����뷮���� ���԰� ū ���
				dp[i][j] = dp[i - 1][j];
			else {		//i��° ������ �ֱ� ���� ��ġ�� i��° ������ ���Ը� ������ ��ġ�� i��° ������ ��ġ ���� �� ��
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