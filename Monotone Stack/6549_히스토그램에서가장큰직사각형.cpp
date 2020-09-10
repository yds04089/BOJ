#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<deque>
using namespace std;

int main()
{
    while (1) {
        int n;
        scanf("%d", &n);
        if (!n)
            break;
        vector<int> arr;
        deque<int> s;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            arr.push_back(tmp);
        }
        long long ans = 0;
        long long length, height;
        for (int i = 0; i < arr.size(); i++) {
            while (!s.empty() && arr[i] < arr[s.back()]) {
                height = arr[s.back()];
                s.pop_back();
                if (s.empty())
                    length = i;
                else
                    length = i - s.back() - 1;
                ans = max(ans, height * length);
            }
            s.push_back(i);
        }
        while (!s.empty()) {    //덱에 남은 것들 빼내는 과정
            height = arr[s.back()];
            s.pop_back();
            length = n;
            if (!s.empty())
                length = length - s.back() - 1;
            ans = max(ans, height * length);
        }

        printf("%lld\n", ans);
    }
    return 0;
}