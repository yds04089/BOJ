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


int main()
{
    while(1){
        string s;
        cin >> s;
        if (s[0] == '.')
            break;
        int ans = 1;
        vector<int> fail = make_fail(s);
        int leng = fail.size() - 1;
        ans = s.size() / (s.size() - fail[leng]);
        if (fail[leng] == 0 || fail[leng]%(fail.size() - fail[leng]))
            printf("1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}