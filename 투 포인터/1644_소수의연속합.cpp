#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
bool isprime[4000001];

void che() {    //에라토스테네스의 체
    fill(isprime, isprime + 4000001, true);
    for (long long i = 2; i <= 4000000; i++) {
        if (!isprime[i])
            continue;
        arr.push_back(i);
        for (long long j = i * i; j <= 4000000; j += i) {
            isprime[j] = false;
        }
    }
}

int two_pointer(int n, int m) {
    int lo = 0, hi = 0, cnt = 0, sum = 0;
    while (1) {
        if (hi > n || lo > m)
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
    return cnt;
}


int main()
{
    che();
    int n;
    scanf("%d", &n);
    int ans = two_pointer(arr.size(), n);
    printf("%d\n", ans);
    return 0;
}