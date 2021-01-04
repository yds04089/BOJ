#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

int arr[1299710];
const int maxnum = 1299709;

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
	scanf("%d", &n);
	che();
	while (n--) {
		int k;
		scanf("%d", &k);
		if (arr[k] == 0) {
			printf("0\n");
			continue;
		}
		int cnt = 1;
		for (int i = k; i > 1; i--) {
			if (arr[i] == 0)
				break;
			cnt++;
		}
		for (int i = k + 1; i <= maxnum; i++) {
			if (arr[i] == 0)
				break;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}