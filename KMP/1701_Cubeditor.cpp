#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>

using namespace std;

vector<int> make_fail(string p) {
    int p_size = p.size();
    int j = 0;
    vector<int> ans(p_size, 0);
    for (int i = 1; i < p_size; i++) {
        while (j > 0 && p[i] != p[j])
            j = ans[j - 1];
        if (p[i] == p[j])
            ans[i] = ++j;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        string tmp = s.substr(i, s.size());
        vector<int> p = make_fail(tmp);
        sort(p.begin(), p.end());
        ans = max(ans, p[p.size() - 1]);
    }
    printf("%d\n", ans);
    return 0;
}