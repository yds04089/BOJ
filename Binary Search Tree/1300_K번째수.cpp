#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;


long long bst(int n, int m)	//binary search tree
{
	int mid;
	int left = 1, right = m;
	int ans = 1;
	while (right>=left) {
		mid = (left + right) / 2;	//mid는 현재 보고있는 수
		long long cnt = 0;	
		for (int i = 1; i <= n; i++) {	//cnt는 mid보다 작거나 같은 수의 개수
			cnt += min(n, mid / i);
		}

		if (cnt < m) {
			left = mid + 1;
		}
		else{
			right = mid - 1;
			ans = mid;
		}
	}
	return ans;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", bst(n, m));
	return 0;
}