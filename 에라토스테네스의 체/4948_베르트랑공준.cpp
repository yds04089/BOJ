#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

int arr[250000];
int main()
{
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		int cnt = 0;
		for (long long i = 2; i <= 2 * n; i++) {	//에라토스테네스의 체
			if (arr[i] == 1)
				continue;
			for (long long j = i * i; j <= 2 * n; j += i) {
				arr[j] = 1;
			}
		}
		for (int i = n + 1; i <= 2 * n; i++)
			if (arr[i] == 0)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}