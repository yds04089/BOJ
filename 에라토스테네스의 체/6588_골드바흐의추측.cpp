#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

int arr[1000001];
const int maxnum = 1000000;

void che()	//에라토스테네스의 체
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
	int n;
	che();
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		bool isexist = false;
		for (int i = 3; i < n; i += 2) {
			if (!arr[i] && !arr[n - i]) {
				isexist = true;
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		if (!isexist)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}