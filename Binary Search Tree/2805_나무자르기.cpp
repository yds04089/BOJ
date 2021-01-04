#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int arr[1000000];

int bst(int n, int find)	//binary search tree
{
	int mid;
	int left = 0, right = 1000000000;
	while (right-left>1) {
		mid = (left + right) / 2;	//mid는 절단기에 설정한 높이
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] > mid) sum += arr[i] - mid;
		if (sum < find) {
			right = mid;
		}
		else if (sum > find) {
			left = mid;
		}
		else 
			return mid;
	}
	return left;
}



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", bst(n, m));
	return 0;
}