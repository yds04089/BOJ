#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include<vector>

using namespace std;

//vector<int> arr[1001];
int v[101][101];
char ch[101][101];

typedef struct {
    int x, y;
}direction;

direction dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int m, n, k;

void dfs(int x, int y) {
    v[x][y] = 1;
    char now = ch[x][y];
    int nextX;
    int nextY;
    for (int i = 0; i < 4; i++) {
        nextX = x + dir[i].x;
        nextY = y + dir[i].y;
        if (nextX >= 0 && nextY < n && nextX < n && nextY >= 0) {
            if (ch[nextX][nextY] == now && v[nextX][nextY] == 0) {
                dfs(nextX, nextY);
            }
        }
    }
}

int main() {
    int cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //scanf("%c", &ch[i][j]);
            cin >> ch[i][j];
        }
    }
    //적록색약 아닌 경우
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                dfs(i, j);
                cnt1++;
            }
        }
    }
    //적록색약인 경우
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ch[i][j] == 'R')
                ch[i][j] = 'G';
            v[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                dfs(i, j);
                cnt2++;
            }
        }
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}