#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 987654321
vector<int> arr[1001];
priority_queue<int> pq;
int main()
{
	int n;
	scanf("%d", &n);
	int max_n = 0;		
	for (int i = 0; i < n; i++) {
		int d, w;
		scanf("%d%d", &d, &w);
		arr[d].push_back(w);
		max_n = max(max_n, d);	//n이 d의 최대값보다 작을 수 있기 때문에 d의 최댓값 찾음
	}
	for (int i = 1; i <= max_n; i++) {
		if (arr[i].size() == 1 || arr[i].empty() == 1) continue;	//점수가 비거나 하나뿐이면 무시
		for (int j = 0; j < arr[i].size(); j++) {
			pq.push(arr[i][j]);		//같은 d의 점수 중 최댓값 찾으려고 pq에 다 넣어줌
		}
		arr[i][0] = pq.top();	//최댓값만 빼줌
		pq.pop();
		while (!pq.empty()) {
			int now = pq.top();		//d에 있던 최댓값을 제외한 다른 점수들
			pq.pop();
			int min = INF;
			int min_x = INF;
			for (int j = 1; j < i; j++) {	//d보다 마감시간 빠른 것들만 탐색
				if (arr[j].empty() == 1) {	//점수가 안들어있는 d인 경우
					min = 0;
					min_x = j;
				}
				else if (min > arr[j][0]) {	//d보다 앞부분 중 최솟값 찾기
					min = arr[j][0]; 
					min_x = j;
				}
			}
			if (min == 0) arr[min_x].push_back(now);	//점수 빈 부분 있으면 거기에 pq에서 뽑은 값 삽입
			else if (min < now) arr[min_x][0] = now;	//최솟값보다 pq에서 뽑은 값이 더 작으면 그 자리에 삽입
		}
	}
	int ans = 0;
	for (int i = 1; i <= max_n; i++) {
		if (arr[i].empty()) continue;	//비어있는 경우는 무시
		ans += arr[i][0];
	}
	printf("%d\n", ans);
	return 0;
}