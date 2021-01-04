#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;


int dp[501];
vector<pair<int, int>> arr;

int LIS(int n)	//LIS �˰���
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second && dp[i] <= dp[j])
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
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		arr.push_back(make_pair(n1, n2));
		dp[i] = 1;
	}
	sort(arr.begin(), arr.end());	//�ϴ� �� �����븦 �������� ����
	int ans = LIS(n);
	printf("%d\n", n - ans);	//��ü ������ ������ LIS�� ũ�⸦ ���� �䳪��
	return 0;
}