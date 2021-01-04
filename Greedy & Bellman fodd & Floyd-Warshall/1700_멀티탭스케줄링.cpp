#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

#define INF 123456789
int arr[101];
int tab[101];

int check(int num, int n)
{
	for (int i = 0; i < n; i++) {
		if (tab[i] == num)
			return -1;		//이미 멀티탭에 꽂혀있는 경우
		else if (tab[i] == 0)
			return i;		//멀티탭에 빈자리 있는 경우
	}
	return -2;				//멀티탭을 뽑아야하는 경우
}

int choose(int n, int k, int now)
{
	int max = 0;
	int chosen_idx = -1;
	for (int i = 0; i < n; i++) {	//멀티탭의 전자기기들
		int tmpmax = 0;
		for (int j = now; j < k; j++) {	//멀티탭에 있는 전자기기가 미래에 또 쓰이는 경우
			if (tab[i] == arr[j]) {	
				tmpmax = j;
				break;				//가장 가까이 있는 인덱스를 가져옴
			}
		}
		if (tmpmax == 0)			//만약 앞으로 안쓰인다면 그 전자기기의 멀티탭 인덱스를 리턴
			return i;
		if (max < tmpmax) {			//가장 뒤늦게 재등장하는 전자기기의 인덱스 가져옴
			max = tmpmax;
			chosen_idx = i;
		}
	}
	return chosen_idx;
}

int main()
{
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	if (n >= k) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < k; i++) 
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (check(arr[i], n) >= 0)
			tab[i] = arr[i];
	}
	for (int i = n; i < k; i++) {
		if (check(arr[i], n) == -1)	//이미 꽂혀있는 경우
			continue;
		if (check(arr[i], n) >= 0) {	//빈자리 있는 경우
			int idx = check(arr[i], n);
			tab[idx] = arr[i];
			continue;
		}
		int idx;				
		idx = choose(n, k, i);		//멀티탭에 바꿔껴야 하는 경우
		tab[idx] = arr[i];			//choose()에서 받아온 멀티탭인덱스에 새로운 전자기기 넣음
		ans++;					//바꿔낀 횟수 증가
	}
	printf("%d\n", ans);
	return 0;
}