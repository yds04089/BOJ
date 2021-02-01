#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<queue>
#include<vector>
#include<stack>

using namespace std;
pair<pair<int, int>, int> arr[10001];
int truck[2001];

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    if (a.first.second == b.first.second) 
        return a.first.first < b.first.first;
    else 
        return a.first.second < b.first.second;
}

int main() {
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arr[i].first.first, &arr[i].first.second, &arr[i].second);
    }
    sort(arr, arr + m, cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            cnt = max(cnt, truck[j]);
        }
        int space = min(arr[i].second, c - cnt);
        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            truck[j] += space;
        }
        ans += space;
    }
    printf("%d\n", ans);
    return 0;
}