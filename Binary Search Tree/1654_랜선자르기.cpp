#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

long long arr[10000];

long long bst(int n, int m)	//binary search tree
{
	long long mid;
	long long left = 0, right = LLONG_MAX;
	long long ans = 0;
	while (right>=left) {
		mid = (left + right) / 2;	//mid는 랜선 최대 길이
		int cnt = 0;
		for (int i = 0; i < n; i++) {	//랜선 개수 셈
			cnt += arr[i] / mid;
		}

		if (cnt < m) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
			if (ans < mid)
				ans = mid;
		}
	}
	return ans;
}



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	printf("%lld\n", bst(n, m));
	return 0;
}