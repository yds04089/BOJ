#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int arr[11];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = n; i > 0; i--)	//���������� �ǰ� �迭�� ����
		scanf("%d", &arr[i]);
	int val = k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] <= val) {	//i��° ������ �� �۴ٸ�
			ans += val / arr[i];//i��° ������ ����
			val = val % arr[i];	//�׷��� ���� ��
		}
	}
	printf("%d\n", ans);
	return 0;
}