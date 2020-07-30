#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int arr[10000001];
const long long maxnum = 10000000;

void che(long long a, long long b)	//에라토스테네스의 체
{
	for (long long i = 2; i <= maxnum; i++) {
		if (arr[i] == 1)
			continue;
		for (long long j = i * i; j <= maxnum; j += i) {
			arr[j] = 1;
		}
	}
}
int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	che(a, b);
	int cnt = 0;
	long long now;
	for (int i = 2; i <= maxnum; i++) {
		if (arr[i] == 1)
			continue;
		if (i > b)
			break;
		now = i;
		while (1) {
			if (now > b/i) {	//오버플로우 방지
				break;
			}
			now = now * i;
			if (now >= a)
				cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}