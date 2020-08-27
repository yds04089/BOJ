#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>

using namespace std;

int fail[1000001];
void make_fail(string p) {
    int p_size = p.size();
    int j = 0;
    for (int i = 1; i < p_size; i++) {
        while (j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
    }
}

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

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    string t, p;
    cin >> t;
    for (int i = 0; i < 2 * n + 1; i++) {
        if (i % 2 == 0)
            p.push_back('I');
        else
            p.push_back('O');
    }
    make_fail(p);
    vector<int> ans = kmp(t, p);
    printf("%d\n", ans.size());
    return 0;
}