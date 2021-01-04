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
int cnt[1000001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
        cnt[tmp]++;
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}