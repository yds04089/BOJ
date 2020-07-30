#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

int main()
{
    int n;
    scanf("%d", &n);
    double sx, sy;
    scanf("%lf %lf", &sx, &sy);
    pair<double, double> prev, now;
    long double ans = 0;
    for (int i=2; i<=n; i++){
        if (i == 2) {
            scanf("%lf %lf", &prev.first, &prev.second);
            continue;
        }
        scanf("%lf %lf", &now.first, &now.second);
        ans += cross(prev.first - sx, prev.second - sy, now.first - sx, now.second - sy);
        prev = now;
    }
    if (ans < 0) ans *= -1;
    ans /= 2.0;
    printf("%.1Lf\n", ans);
    return 0;
}
