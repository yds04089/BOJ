#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    while (b > 0)
    {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

ll ee(ll a, ll b, ll& s, ll& t) {  //확장된 유클리드호제법
    if (!b) {
        s = 1, t = 0;
        return a;
    }
    ll q = a / b, r = a % b, sp, tp;
    ll g = ee(b, r, sp, tp);
    s = tp; t = sp - tp * q;
    return g;
}


int main()
{
    ll n, a, x = 0, y = 0;
    scanf("%lld %lld", &n, &a);
    ll ans1 = n - a;
    ll ans2;
    if (gcd(n, a) != 1)
        ans2 = -1;
    else {
        ll g = ee(a, n, x, y);
        ans2 = (x + n) % n;
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
