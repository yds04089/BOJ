#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<deque>
using namespace std;

vector<int> arr;
deque<pair<int, int>> s;

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.front().first < i - l + 1) {
            s.pop_front();
        }
        while (!s.empty() && s.back().second >= arr[i]) {
            s.pop_back();
        }
        s.push_back(make_pair(i, arr[i]));
        ans.push_back(s.front().second);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}