#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include<vector>

using namespace std;

//vector<int> arr[1001];
int v[101][101];
int arr[101][101];

typedef struct {
    int x, y;
}direction;

direction dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int m, n, k, cnt;

void dfs(int x, int y) {
    v[x][y] = 1;
    cnt++;
    int nextX;
    int nextY;
    for (int i = 0; i < 4; i++) {
        nextX = x + dir[i].x;
        nextY = y + dir[i].y;
        if (nextX >= 0 && nextY < n && nextX < m && nextY >= 0 && v[nextX][nextY] == 0 && arr[nextX][nextY] == 0) {
            dfs(nextX, nextY);
        }
    }
}

int main() {
    vector<int> res;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        for (int x = x1; x < x2; x++)
            for (int y = y1; y < y2; y++)
                arr[x][y] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0 && arr[i][j]==0) {
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    return 0;
}