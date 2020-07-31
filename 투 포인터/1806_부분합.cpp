#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int two_pointer(int n, int m) {
    int lo = 0, hi = 0, min = 100000000; 
    long long sum = 0;
    while (1) {
        if (sum >= m) {
            if (hi - lo < min)
                min = hi - lo;
            sum -= arr[lo++];
        }
        else if (hi >= n)
            break;
        else
            sum += arr[hi++];
        /*if (sum == m) {
            if (hi - lo < min)
                min = hi - lo;
        }*/
    }
    if (min == 100000000)
        return 0;
    else
        return min;
}


int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr.push_back(num);
    }
    int ans = two_pointer(n, s);
    printf("%d\n", ans);
    return 0;
}