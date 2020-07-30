#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

typedef long long ll;

const ll DIV = 1000000007;
map<ll, ll> mem;

ll fib(ll n) {  //큰 수에 대해서는 다른 피보나치 점화식 써서 구할 수 있음
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (mem[n] > 0)
        return mem[n];
    else if (n % 2 == 0) {
        ll mid = n / 2;
        ll tmp1 = fib(mid - 1);
        ll tmp2 = fib(mid);
        mem[n] = ((2 * tmp1 + tmp2) * tmp2) % DIV;
        return mem[n];
    }
    else {
        ll mid = (n + 1) / 2;
        ll tmp1 = fib(mid);
        ll tmp2 = fib(mid - 1);
        mem[n] = (tmp1 * tmp1 + tmp2 * tmp2) % DIV;
        return mem[n];
    }

}

int main()
{
    ll n;
    scanf("%lld", &n);
    ll ans = fib(n);
    printf("%lld\n", ans);
    return 0;
}
