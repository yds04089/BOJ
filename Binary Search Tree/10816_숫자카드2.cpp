#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int card[500001];

//bst에서 find의 위치를 찾았을 때 앞뒤로 binary search를 하면서 find의 개수를 찾아줌
int bst_cnt(int find, int mid, int left, int right)	
{
	int left_ = left;
	int right_ = mid;
	int cnt = 0;
	int left_idx = mid;
	while (left_ <= right_) {	//찾아낸 위치의 왼쪽 부분을 보면서 가장 왼쪽에 있는 find의 위치 찾아줌
		int mid_left = (left_ + right_) / 2;
		if (card[left_] == find) {
			left_idx = left_;
			break;
		}
		if (card[mid_left] == find) {
			right_ = mid_left;
		}
		else if (card[mid_left] < find) {
			left_ = mid_left;
		}
		if (right_ - left_ == 1) {
			left_idx = right_;
			break;
		}
	}
	left_ = mid;
	right_ = right;
	int right_idx = mid;
	while (left_ <= right_) {	//찾아낸 위치의 오른쪽 부분을 보면서 가장 오른쪽에 있는 find의 위치 찾아줌
		int mid_right = (left_ + right_) / 2;
		if (card[right_] == find) {
			right_idx = right_;
			break;
		}
		if (card[mid_right] == find) {
			left_ = mid_right;
		}
		else if (card[mid_right] > find) {
			right_ = mid_right;
		}
		if (right_ - left_ == 1) {
			right_idx = left_;
			break;
		}
	}
	cnt = right_idx - left_idx + 1;		//가장 오른쪽 위치에서 가장 왼쪽 위치를 빼서 find의 개수를 찾아줌
	return cnt;
}

int bst(int n, int find)	//binary search tree
{
	int left = 0, right = n-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (card[mid] > find) {
			right = mid - 1;
		}
		else if (card[mid] < find) {
			left = mid + 1;
		}
		else {
			int cnt = 0;
			cnt = bst_cnt(find, mid, left, right);
			return cnt;
		}
	}
	return 0;
}



int main()
{
	int n, m, check;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	sort(card, card + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &check);
		printf("%d ", bst(n, check));
	}
	return 0;
}