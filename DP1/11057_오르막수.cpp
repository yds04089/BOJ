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
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];	//��ȭ��
				dp[i][j] %= 10007;
			}
		}
	int ans = dp[n + 9][9];	//�ߺ����� 10Hn�� ���ؾ��ؼ� �������� ��Ÿ���� (9+n)C9�� ��
	printf("%d\n", ans);
	return 0;
}