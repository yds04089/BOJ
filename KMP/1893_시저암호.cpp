#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

map<char, char> order;
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
    while (n--) {
        vector<int> ans;
        string a, w, s;
        cin >> a >> w >> s;
        for (int i = 0; i < a.size() - 1; i++) {
            order[a[i]] = a[i + 1];
        }
        order[a[a.size() - 1]] = a[0];
        string newstr = w;
        for (int i = 0; i < a.size(); i++) {
            vector<int> res = kmp(s, newstr);
            if (res.size() == 1)
                ans.push_back(i%a.size());
            for (int j = 0; j < w.size(); j++) {
                newstr[j] = order[newstr[j]];
            }
        }
        if (ans.size() == 0)
            printf("no solution\n");
        else if (ans.size() == 1)
            printf("unique: %d\n", ans[0]);
        else {
            printf("ambiguous: ");
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}