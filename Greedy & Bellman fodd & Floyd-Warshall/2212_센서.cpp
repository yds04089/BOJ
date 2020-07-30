#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

vector<int> arr;
int dist[10001];
priority_queue <int> pq;	//거리의 최댓값 뽑아주는 pq

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	k--;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int longdist = arr[n-1] - arr[0];	//가장 거리 먼 두 센서 거리
	for (int i = 1; i < n; i++) {
		dist[i] = arr[i] - arr[i - 1];
		pq.push(dist[i]);				//거리의 최댓값 구하려고 pq에 넣음
	}
	int maxsum = 0;
	while (k > 0 && !pq.empty()) {	//pq가 비었을 때 예외처리도 해줌
		maxsum += pq.top();			//집중국 개수-1개 만큼 거리최댓값 구해서 더함 
		pq.pop();	
		k--;
	}
	printf("%d\n", longdist - maxsum);	//가장 먼 두 센서거리 - 연속된 두 센서의 거리중 최댓값들의 합
	return 0;
}