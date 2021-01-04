#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

struct pos {
    long long x, y;
};

pos arr[100001];

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
        while (s.size()>=2) {
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
    printf("%d\n", s.size());
    return 0;
}