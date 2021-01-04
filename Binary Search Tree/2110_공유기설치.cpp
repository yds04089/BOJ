#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

long long arr[200000];

long long bst(int n, int m)	//binary search tree
{
	long long mid;
	long long left = 1, right = arr[n-1] - arr[0];
	long long ans = 0;
	while (right>=left) {
		mid = (left + right) / 2;	//mid는 가장 인접한 두 공유기 사이 거리
		int cnt = 1;
		int have = arr[0];		
		for (int i = 1; i < n; i++) {	//cnt는 설치한 공유기 개수
			if (arr[i] - have >= mid) {
				cnt++;
				have = arr[i];
			}
		}

		if (cnt < m) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
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
	sort(arr, arr + n);
	printf("%lld\n", bst(n, m));
	return 0;
}