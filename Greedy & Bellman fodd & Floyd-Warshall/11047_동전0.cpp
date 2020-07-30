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
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = n; i > 0; i--)	//내림차순이 되게 배열에 삽입
		scanf("%d", &arr[i]);
	int val = k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] <= val) {	//i번째 동전이 더 작다면
			ans += val / arr[i];//i번째 동전의 개수
			val = val % arr[i];	//그러고 남은 돈
		}
	}
	printf("%d\n", ans);
	return 0;
}