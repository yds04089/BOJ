#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int prime[2000001];
vector <int> check;

void che() {        //에라토스테네스의 체
    for (long long i = 2; i <= 2000000; i++) {
        if (prime[i] == 1) {
            continue;
        }
        else {
            check.push_back(i);
            for (long long j = i * i; j <= 2000000; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int isPrime(long long n)
{
    int size = check.size();
    for (int i = 0; i < size; i++) {
        if (n <= check[i])
            return 1;
        else if (n % check[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    long long a, b;
    scanf("%d", &t);
    che();
    while (t--) {
        scanf("%lld %lld", &a, &b);
        long long num = a + b;
        if (num < 4) {
            printf("NO\n");
            continue;
        }
        else if (num % 2 == 0) {
            printf("YES\n");
            continue;
        }
        else {
            num -= 2;
            if (isPrime(num))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
