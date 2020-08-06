#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr1[1001];
int arr2[1001];
vector<int> sum1;
vector<int> sum2;

int main()
{
    int t, n, m;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n; i++) {   //부분합들을 미리 구함
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr1[j];
            sum1.push_back(sum);
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += arr2[j];
            sum2.push_back(sum);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    long long cnt = 0;
    for (int i = 0; i < sum1.size(); i++) {
        int diff = t - sum1[i];
        int hi = upper_bound(sum2.begin(), sum2.end(), diff) - sum2.begin();
        int lo = lower_bound(sum2.begin(), sum2.end(), diff) - sum2.begin();
        cnt += (long long)hi - lo;
    }
    printf("%lld\n", cnt);
    return 0;
}