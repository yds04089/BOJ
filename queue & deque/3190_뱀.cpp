#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

int m[101][101];
deque<pair<int, int>> snake;
queue<pair<int, char>> q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int dir=1;

void turn(int c) {
    if (c == 'L') {
        dir = (dir - 1 < 0) ? 3 : dir - 1;
    }
    else {
        dir = (dir + 1 > 3) ? 0 : dir + 1;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        m[n1][n2] = 2;
    }
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int n1;
        char ch;
        cin >> n1 >> ch;
        q.push(make_pair(n1, ch));
    }
    int cnt = 0;
    m[1][1] = 1;
    snake.push_back(make_pair(1, 1));
    while (1) {
        if (!q.empty()) {
            if (q.front().first == cnt) {
                turn(q.front().second);
                q.pop();
            }
        }
        cnt++;
        int next_x = snake.back().first + dx[dir];
        int next_y = snake.back().second + dy[dir];
        if (next_x<1 || next_y <1 || next_x>n || next_y>n)
            break;
        if (m[next_x][next_y] == 1)
            break;
        if (m[next_x][next_y] != 2) {
            m[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        snake.push_back(make_pair(next_x, next_y));
        m[next_x][next_y] = 1;
    }
    printf("%d\n", cnt);
    return 0;
}