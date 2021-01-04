#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> arr;
int v[3001];

int main()
{
    int n, d, k, c;
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    for (int i = 0; i < k - 1; i++)
        arr.push_back(arr[i]);
    int max = 0;
    bool iscoupon = false;
    int cnt = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (i == 0) {   //Ã¹¹øÂ° set ¸¸µë
            for (int j = 0; j < k; j++) {
                if (arr[j] == c)
                    iscoupon = true;
                s.insert(arr[j]);
                v[arr[j]]++;
            }
            cnt = (iscoupon) ? s.size() : s.size() + 1;
            if (cnt > max)
                max = cnt;
            continue;
        }
        if (--v[arr[i - 1]] == 0) {
            s.erase(arr[i - 1]);
            if (arr[i - 1] == c && iscoupon == true)
                iscoupon = false;
        }
        s.insert(arr[i + k - 1]);
        v[arr[i + k - 1]]++;
        if (arr[i + k - 1] == c)
            iscoupon = true;
        cnt = (iscoupon) ? s.size() : s.size() + 1;
        if (cnt > max)
            max = cnt;
    }
    printf("%d\n", max);
    return 0;
}