#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[2][3];
int dp_max[2][3];
int dp_min[2][3];

int main()
{
    int n;
    scanf("%d", &n);
    int prev, now;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            now = 0;
            prev = 1;
        }
        else {
            now = 1;
            prev = 0;
        }
        for (int j = 0; j < 3; j++)
            scanf("%d", &arr[now][j]);
        if (i == 0) {
            for (int k = 0; k < 3; k++) {
                dp_max[i][k] = arr[i][k];
                dp_min[i][k] = arr[i][k];
            }
            continue;
        }
        
        dp_max[now][0] = max(dp_max[prev][0], dp_max[prev][1]) + arr[now][0];
        dp_max[now][1] = max(max(dp_max[prev][0], dp_max[prev][1]), dp_max[prev][2]) + arr[now][1];
        dp_max[now][2] = max(dp_max[prev][1], dp_max[prev][2]) + arr[now][2];

        dp_min[now][0] = min(dp_min[prev][0], dp_min[prev][1]) + arr[now][0];
        dp_min[now][1] = min(min(dp_min[prev][0], dp_min[prev][1]), dp_min[prev][2]) + arr[now][1];
        dp_min[now][2] = min(dp_min[prev][1], dp_min[prev][2]) + arr[now][2];
    }
    int num = (n - 1) % 2;
    int ans_max = max(max(dp_max[num][0], dp_max[num][1]), dp_max[num][2]);
    int ans_min = min(min(dp_min[num][0], dp_min[num][1]), dp_min[num][2]);
    printf("%d %d\n", ans_max, ans_min);
    return 0;
}