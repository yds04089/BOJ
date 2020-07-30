#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll fib[4000001];

ll powfunc(ll a, ll b) {
    ll ret = 1;
    while (1) {
        if (b & 1)
            ret = (ret * a) % mod;
        if (b /= 2)
            a = (a * a) % mod;
        else
            break;
    }
    return ret;
}


/*ll ee(ll a, ll b, ll& s, ll& t) {  //확장된 유클리드호제법
    if (!b) {
        s = 1, t = 0;
        return a;
    }
    ll q = a / b, r = a % b, sp, tp;
    ll g = ee(b, r, sp, tp);
    s = tp; t = sp - tp * q;
    return g;
}*/


int main()
{
    int m;
    scanf("%d", &m);
    fib[0] = 1;
    for (ll i = 1; i <= 4000000; i++) {
        fib[i] = i * fib[i - 1];
        fib[i] %= mod;
    }
    while (m--) {
        int n, k;
        scanf("%d %d", &n, &k);
        ll ans = fib[n];
        ll tmp = (fib[k] * fib[n - k]) % mod;
        ans *= powfunc(tmp, mod - 2);
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}
