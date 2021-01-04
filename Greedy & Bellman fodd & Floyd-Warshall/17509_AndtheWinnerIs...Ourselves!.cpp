#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int arr[11];
int main()
{
	int n = 11;
	int sum = 0;
	int sumv = 0;
	for (int i = 0; i < n; i++) {
		int d, v;
		scanf("%d%d", &arr[i], &v);
		sumv += 20 * v;
	}
	sort(arr, arr + 11);	//가장 작은게 먼저오게 정렬
	for (int i = 0; i < n; i++) {	//배열의 내용을 누적합으로 바꿈
		sum += arr[i];
		arr[i] = sum;
	}
	int ans_sum = 0;
	for (int i = 0; i < n; i++)
		ans_sum += arr[i];
	printf("%d\n", ans_sum + sumv);
	return 0;
}