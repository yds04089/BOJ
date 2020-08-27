#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

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

vector<int> kmp(string t, string p) {
    int t_size = t.size();
    int p_size = p.size();
    int j = 0;
    vector<int> ans;
    vector<int> fail = make_fail(p);
    for (int i = 0; i < t_size; i++) {
        while (j > 0 && t[i] != p[j])
            j = fail[j - 1];
        if (t[i] == p[j]) {
            if (j == p_size - 1) {
                ans.push_back(i - p_size + 1);
                j = fail[j];
            }
            else
                j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    string s1, s2;
    s1.clear();
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        s1 += tmp;
    }
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        s2 += tmp;
    }
    s2 += s2;
    s2.pop_back();
    vector<int> ans = kmp(s2, s1);
    int cnt = ans.size();
    int gcdnum = gcd(cnt, n);
    cnt /= gcdnum;
    n /= gcdnum;
    printf("%d/%d\n", cnt, n);
    return 0;
}