#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int arr[10000];

int bst(int n, int find)	//binary search tree
{
	int mid;
	int left = 0, right = 100000;
	while (right-left>1) {
		mid = (left + right) / 2;	//mid�� ���� �ִ�
		long long sum = 0;
		for (int i = 0; i < n; i++)
			sum += min(arr[i], mid);
		if (sum < find) {
			left = mid;
		}
		else if (sum > find) {
			right = mid;
		}
		else 
			return mid;
	}
	return left;
}



int main()
{
	int n, m;
	int sum = 0;
	int maxnum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		maxnum = max(maxnum, arr[i]);
	}
	scanf("%d", &m);
	if (sum <= m) {	//�̹� ���� ���������� �׳� ���� �� �ִ� ����ϰ� ����
		printf("%d\n", maxnum);
		return 0;
	}
	printf("%d\n", bst(n, m));
	return 0;
}