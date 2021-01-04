#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<set>
#include<math.h>
using namespace std;

int prime[1000001];
const int maxnum = 1000000;

void che()	//�����佺�׳׽��� ü
{
	for (long long i = 2; i <= maxnum; i++) {	
		if (prime[i] == 1)
			continue;
		for (long long j = i * i; j <= maxnum; j += i) {
			prime[j] = 1;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	che();
	for (int i = 2; i <= n; i++) {
		if (prime[i])	//�Ҽ��� �ƴϸ� ����
			continue;
		set<int> s;
		s.insert(1);
		int num = i;
		while (1) {
			num = pow(num % 10, 2) + pow(num / 10 % 10, 2) + pow(num / 100 % 10, 2) + pow(num / 1000 % 10, 2) + pow(num / 10000 % 10, 2) + pow(num / 100000 % 10, 2) + pow(num / 1000000 % 10, 2);
			if (num == 1) {
				printf("%d\n", i);
				break;
			}
			auto it = s.find(num);
			if (it != s.end()) {	//�̹� set �ȿ� ������ ��ټ��� �ƴ�
				break;
			}
			s.insert(num);
		}

	}
		
	return 0;
}