#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;



int isPrime(int n)	
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long powfunc(long long a, long long b, long long c) {
    long long ret = 1;
    while (1) {
        if (b & 1)
            ret = (ret * a) % c;
        if (b /= 2)
            a = (a * a) % c;
        else
            break;
    }
    return ret;
}


int main()
{
    while (1) {
        int p, a;
        scanf("%d %d", &p, &a);
        if (!a && !p)
            break;
        long long num = powfunc(a, p, p);
        if (num == a) {
            if (isPrime(p))
                printf("no\n");
            else
                printf("yes\n");
        }
        else 
            printf("no\n");
    }
    return 0;
}
