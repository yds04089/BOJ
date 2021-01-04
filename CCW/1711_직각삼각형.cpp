#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

long long x[1500], y[1500];

/*int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}*/

unsigned long long distance(long long x1, long long y1, long long x2, long long y2) {
    return ((x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%lld %lld", &x[i], &y[i]);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                unsigned long long a, b, c;
                a = distance(x[i], y[i], x[j], y[j]);
                b = distance(x[j], y[j], x[k], y[k]);
                c = distance(x[k], y[k], x[i], y[i]);
                if (a + b == c || b + c == a || c + a == b)
                    cnt++;
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
