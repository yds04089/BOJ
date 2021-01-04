#include<iostream>
#include<vector>

using namespace std;

int arr[10000];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int lo = 0, hi = 0;
    int sum = 0, cnt = 0;
    while (1) {
        if (hi > n)
            break;
        else if (sum > m)
            sum -= arr[lo++];
        else if (sum < m)
            sum += arr[hi++];
        else if (sum == m) {
            cnt++;
            sum += arr[hi++];
        }
    }
    printf("%d\n", cnt);
    return 0;
}