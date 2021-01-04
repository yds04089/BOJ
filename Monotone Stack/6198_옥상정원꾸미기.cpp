#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

vector<int> arr;
stack<int> s;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    long long ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() <= arr[i]) 
            s.pop();
        ans += s.size();
        s.push(arr[i]);
    }
    printf("%lld", ans);
    return 0;
}