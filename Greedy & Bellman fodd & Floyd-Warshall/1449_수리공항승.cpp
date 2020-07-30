#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int arr[1000];
int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int now = arr[0], dist = l - 1;	//좌우로 0.5씩 떨어져야하기 때문
	int ans = 1;			//첫 시작점은 미리 세줌
	for (int i = 0; i < n; i++) {
		if (arr[i] > now + dist) {	//테이프 범위밖에 구멍 있으면
			now = arr[i];
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}