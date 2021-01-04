#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

vector<pair<long long, long long>> arr;

int main()
{
	long long l, n, rf, rb;
	scanf("%lld%lld%lld%lld", &l, &n, &rf, &rb);
	for (int i = 0; i < n; i++) {
		long long x, c;
		scanf("%lld%lld", &x, &c);
		arr.push_back(make_pair(c, x));
	}
	long long speed = rf - rb;		//농부와 베시의 속도차
	sort(arr.begin(), arr.end(), greater<pair<long long, long long>>());
	long long ans = 0;
	long long ex_x;
	for (int i = 0; i < arr.size(); i++) {
		long long now_x, now_c;
		now_x = arr[i].second;
		now_c = arr[i].first;
		if (i == 0) {	//첫번째 경우만 따로 처리 (ex_x 때문)
			ex_x = now_x;
			ans = now_c * speed * now_x;
			continue;
		}
		if (ex_x >= now_x)	//새로운 x가 이전의 x보다 작으면 무시
			continue;
		ans += now_c * (now_x - ex_x) * speed;	
		ex_x = now_x;		//ex_x 업데이트
	}
	printf("%lld\n", ans);
}