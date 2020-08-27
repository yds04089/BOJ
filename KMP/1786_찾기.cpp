#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int fail[1000001];

vector<int> kmp(string t, string p) {
    int t_size = t.size();
    int p_size = p.size();
    int j = 0;
    vector<int> ans;
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

void make_fail(string p) {
    int p_size = p.size();
    int j = 0;
    for (int i = 1; i < p_size; i++) {
        while (j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j]) {
            fail[i] = ++j;
        }
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    make_fail(p);
    vector<int> ans = kmp(t, p);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i] + 1);
    return 0;
}