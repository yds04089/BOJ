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

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    int c = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    if (c > 0)
        printf("1\n");
    else if (c < 0)
        printf("-1\n");
    else
        printf("0\n");
    return 0;
}
