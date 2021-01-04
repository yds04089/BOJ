#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int two_pointer(int n, int m) {
    int lo = 0, hi = 0, min = 2000000000; 
    int diff = -1;
    while (1) {
        if (hi >= n || lo >= n)  //m이 0일때를 위해 lo>=n을 추가했음
            break;
        else if (diff >= m) {
            diff = arr[hi] - arr[lo++];
        }
        else
            diff = arr[hi++] - arr[lo];
        if (diff >= m) {
            if (diff < min)
                min = diff;
        }
    }
    if (min == 2000000000)
        return 0;
    else
        return min;
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int ans = two_pointer(n, m);
    printf("%d\n", ans);
    return 0;
}