#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
#include<utility>
using namespace std;

int visit[26][26];
int arr[26][26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> house;
int house_num;

void dfs(pair<int, int> v, int n)
{
	visit[v.first][v.second] = 1;
	house_num++;					//house_num 증가
	for (int i=0;i<4;i++)			//4방향에서 dfs
	{
		if (v.first+dx[i]<0 || v.second+dy[i]<0 || v.first+dx[i]>=n || v.second+dy[i]>=n)
			continue;					//만일 범위 밖이면 무시
		pair<int, int> next= make_pair(v.first+dx[i], v.second+dy[i]);
		if (arr[next.first][next.second]==1 && visit[next.first][next.second]==0)
		{
			dfs(next, n);
		}
	}
}

int main()
{
	int n;
	int cnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);	//붙어있는 숫자들이라서 이렇게해야 숫자하나씩 받아짐
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (visit[i][j]==0 && arr[i][j]==1)		//아직 방문하지 않았고 값이 1인것만 방문
			{
				house_num=0;						//새로운 dfs마다 hous_num 초기화
				dfs(make_pair(i, j), n);
				house.push_back(house_num);		//house배열에 house_num값 삽입
				cnt++;							//연결된 단지의 개수 하나 증가
			}
		}
	}

	sort(house.begin(), house.end());		//오름차순 정렬
	printf("%d\n", cnt);
	for (int i = 0; i < house.size(); i++)
		printf("%d\n", house[i]);
	return 0;
}