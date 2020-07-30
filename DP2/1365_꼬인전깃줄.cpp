#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;


int dp[100001];
int L[100001];
vector<int> arr;

int LIS(int n)	//LIS 알고리즘 (Lower bound 사용)
{
	int size = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(L, L + size, arr[i]) - L;
		if (idx == size) {
			L[size] = arr[i];
			size++;
		}
		else
			L[idx] = arr[i];
	}
	return size;
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
	printf("%d\n", n - ans);	//전체 전봇대 수 - LIS길이
	return 0;
}