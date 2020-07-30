#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

vector <pair<int, int>> order;	//<시작시간, 끝나는시간>
priority_queue <int, vector<int>, greater<int>> pq;	//각 강의가 끝나는 시간

int main()
{
	int n;
	int s, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &t);
		order.push_back(make_pair(s, t));
	}
	sort(order.begin(), order.end());	//배열 안의 순서 정렬
	pq.push(order[0].second);			//pq에 첫번째 끝나는시간 넣어줌
	int ans = 1;					//첫 강의는 무조건 강의실 필요하기 때문	
	for (int i = 1; i < order.size(); i++) {
		if (order[i].first >= pq.top()) {	//같은 강의실 사용가능하면
			pq.pop();
			pq.push(order[i].second);		//pq값 업데이트
		}
		else {						//새로운 강의실 필요하면
			pq.push(order[i].second);	//pq에 새로운 강의 끝나는 시간 넣어줌
			ans++;		//강의실 하나 추가됐으므로 ans++
		}
	}
	printf("%d\n", ans);
	return 0;
}