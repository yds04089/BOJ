#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int a, m;
    scanf("%d %d", &a, &m);
    int cnt = 1;
    int a_init = a;
    while (1) {
        if (a % m == 1) {
            break;
        }
        else {
            cnt++;
            a=a_init*cnt;
        }
    }
    printf("%d\n", cnt);
}
