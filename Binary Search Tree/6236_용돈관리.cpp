#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int arr[100000];

int bst(int n, int m, int maxnum)	//binary search tree
{
	int mid;
	int left = maxnum, right = 2123456789 / m;
	while (right >= left) {
		mid = (left + right) / 2;	//mid는 인출해야할 최소금액
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {	//인출 횟수 셈
			if (sum + arr[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += arr[i];
		}
		if (sum != 0)
			cnt++;

		if (cnt <= m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}



int main()
{
	int n, m;
	int maxnum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxnum = max(arr[i], maxnum);
	}
	printf("%d\n", bst(n, m, maxnum));
	return 0;
}