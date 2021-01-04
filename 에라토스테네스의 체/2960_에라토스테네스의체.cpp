#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

bool prime[1001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		prime[i] = true;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {	//에라토스테레스의 체 
		if (prime[i] == false)
			continue;
		cnt++;
		if (cnt == k) {
			printf("%d\n", i);
			return 0;
		}
		for (int j = i*i; j <= n; j += i) {
			if (prime[j] == false)
				continue;
			prime[j] = false;
			cnt++;
			if (cnt == k) {
				printf("%d\n", j);
				return 0;
			}
		}
	}
	return 0;
}