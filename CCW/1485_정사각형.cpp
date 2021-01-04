#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

double dis[6];

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        dis[0] = distance(x1, y1, x2, y2);
        dis[1] = distance(x2, y2, x3, y3);
        dis[2] = distance(x3, y3, x4, y4);
        dis[3] = distance(x4, y4, x1, y1);
        dis[4] = distance(x1, y1, x3, y3);
        dis[5] = distance(x2, y2, x4, y4);
        sort(dis, dis + 6);
        if (dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3] && dis[4] == dis[5])
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
