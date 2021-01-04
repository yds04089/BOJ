#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (!cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1)) {
        printf("-1\n");
        return 0;
    }
    double d12, d23, d31, big, small;
    d12 = distance(x1, y1, x2, y2);
    d23 = distance(x2, y2, x3, y3);
    d31 = distance(x3, y3, x1, y1);
    big = max(max(d12, d23), d31);
    small = min(min(d12, d23), d31);
    double ans = 2 * (big - small);
    printf("%.16lf\n", ans);
    return 0;
}
