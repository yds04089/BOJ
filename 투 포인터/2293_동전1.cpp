#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
int dp[10001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            if (j - arr[i] >= 0)
                dp[j] += dp[j - arr[i]];
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}