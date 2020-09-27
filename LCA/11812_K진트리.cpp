#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<deque>
using namespace std;


long long parent(long long n, long long k) {
    return (n + k - 2) / k;
}

int main()
{
    long long n, k, q;
    scanf("%lld %lld %lld", &n, &k, &q);
    while (q--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        if (k == 1) {
            printf("%lld\n", abs(r - l));
            continue;
        }
        int length = 0;
        while (l != r) {
            while (l > r) {
                length++;
                l = parent(l, k);
            }
            while (l < r) {
                length++;
                r = parent(r, k);
            }
        }
        printf("%d\n", length);
    }
    return 0;
}