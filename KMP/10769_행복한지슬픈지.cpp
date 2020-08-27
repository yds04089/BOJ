#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
    string t;
    getline(cin, t);
    int happy = 0, sad = 0;
    for (int i = 0; i < t.size()-2; i++) {
        if (t[i] == ':' && t[i + 1] == '-') {
            if (t[i + 2] == ')')
                happy++;
            else if (t[i + 2] == '(')
                sad++;
        }
    }
    if (happy > sad)
        printf("happy\n");
    else if (happy < sad)
        printf("sad\n");
    else if (!happy && !sad)
        printf("none\n");
    else
        printf("unsure\n");
    return 0;
}