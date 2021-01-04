#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int main()
{
	int idx = 1;
	while (1) {
		int l, p, v;
		scanf("%d%d%d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)		//입력이 0이면 종료
			break;
		int ans = 0;
		ans = v / p * l + min(l, v % p);	//답 구하는 식
		printf("Case %d: %d\n", idx, ans);
		idx++;
	}
	return 0;
}