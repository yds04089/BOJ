#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

struct pos {
    long long x, y;
};

pos arr[100010];

long long ccw(pos a, pos b, pos c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool comp_pos(pos a, pos b) {
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}

bool sort_ccw(pos a, pos b) {   //반시계 방향으로 정렬
    long long tmp = ccw(arr[0], a, b);
    if (tmp != 0)
        return tmp > 0;
    else
        return (a.x + a.y) < (b.x + b.y);
}

double dist(pos a, pos b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}


int main()
{
    int n;
    stack<pos> s;
    pos fir, sec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }
    sort(arr, arr + n, comp_pos);
    sort(arr + 1, arr + n, sort_ccw);
    s.push(arr[0]);
    s.push(arr[1]);
    for (int i = 2; i < n; i++) {
        while (s.size() >= 2) {
            sec = s.top();
            s.pop();
            fir = s.top();
            if (ccw(fir, sec, arr[i]) > 0) {
                s.push(sec);
                break;
            }
        }
        s.push(arr[i]);
    }
    vector<pos> v;
    while (s.size()) {
        v.push_back(s.top());
        s.pop();
    }
    double ans = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (dist(v[i], v[j]) > ans)
                ans = dist(v[i], v[j]);
        }
    }
    printf("%lf\n", ans);
    return 0;
}