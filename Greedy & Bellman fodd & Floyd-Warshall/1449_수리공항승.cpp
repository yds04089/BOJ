#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

int arr[1000];
int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int now = arr[0], dist = l - 1;	//�¿�� 0.5�� ���������ϱ� ����
	int ans = 1;			//ù �������� �̸� ����
	for (int i = 0; i < n; i++) {
		if (arr[i] > now + dist) {	//������ �����ۿ� ���� ������
			now = arr[i];
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}