#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int g;
    scanf("%d", &g);
    for (int i = 1; i * i < g; i++) 
        if (g % i == 0 && (i + g / i) % 2 == 0)
            arr.push_back((i + g / i) / 2);
    if (arr.empty() == true) {
        printf("-1\n");
        return 0;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
        printf("%d\n", arr[i]);
    return 0;
}