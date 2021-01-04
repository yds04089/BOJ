#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int s[100001];
int t[100001];
vector <pair<int, int>> order;	//<끝나는시간, 시작시간>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i], &t[i]);
		order.push_back(make_pair(t[i], s[i]));
	}
	sort(order.begin(), order.end());
	int ans = 0;
	int now = 0;	//현재 보고있는 시간
	for (int i = 0; i < order.size(); i++) {
		int now_t = order[i].first;
		int now_s = order[i].second;
		if (now <= now_s) {
			now = now_t;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}