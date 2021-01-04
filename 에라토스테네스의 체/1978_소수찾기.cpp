#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;


int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	while (n--) {
		int num, isPrime = 1;
		scanf("%d", &num);
		if (num == 1) continue;
		for (int i = 2; i < num; i++)
			if (num % i == 0) {
				isPrime = 0;
			}
		if (isPrime == 1)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}