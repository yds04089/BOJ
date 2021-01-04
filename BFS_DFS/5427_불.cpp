#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>

using namespace std;
typedef struct{
    int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char arr[1001][1001];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int v[1001][1001];
int w, h;

int bfs() {
    int cnt = 0;
    while (!q1.empty()) {
        int q1_size = q1.size();
        int q2_size = q2.size();
        cnt++;

        //불 이동
        while (q2_size--) {
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = x + moveDir[i].x;
                int next_y = y + moveDir[i].y;
                if (next_x > 0 && next_x <= h && next_y > 0 && next_y <= w) {
                    if (v[next_x][next_y] == 0) {
                        if (arr[next_x][next_y] != '#') {
                            q2.push(make_pair(next_x, next_y));
                            v[next_x][next_y] = 1;
                        }
                    }
                }
            }
        }
        //사람 이동
        while (q1_size--) {
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = x + moveDir[i].x;
                int next_y = y + moveDir[i].y;
                if (next_x == 0 || next_x > h || next_y == 0 || next_y > w) {
                    return cnt;
                }
                if (v[next_x][next_y] == 1)
                    continue;
                if (arr[next_x][next_y] != '.')
                    continue;
                q1.push(make_pair(next_x, next_y));
                v[next_x][next_y] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(v, 0, sizeof(v));
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
        scanf("%d %d", &w, &h);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    v[i][j] = 1;
                    q1.push(make_pair(i, j));
                }
                else if (arr[i][j] == '*') {
                    v[i][j] = 1;
                    q2.push(make_pair(i, j));
                }
            }
        }
        int ans = bfs();
        if (ans == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}