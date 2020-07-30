#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

bool self[10001];
int main()
{
	const int n = 10000;
	for (int i = 1; i <= n; i++)
		self[i] = true;
	for (int i = 1; i <= n; i++) {	//에라토스테레스의 체 응용
		if (self[i] == false)
			continue;
		int num = i;
		while (num <= n) {
			num += num % 10 + num / 10 % 10 + num / 100 % 10 + num / 1000 % 10 + num / 10000 % 10;
			if (num > n)
				break;
			self[num] = false;
		}
		if (self[i])
			printf("%d\n", i);
	}
	return 0;
}