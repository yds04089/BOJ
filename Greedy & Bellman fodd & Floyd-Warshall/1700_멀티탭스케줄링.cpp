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
			return -1;		//�̹� ��Ƽ�ǿ� �����ִ� ���
		else if (tab[i] == 0)
			return i;		//��Ƽ�ǿ� ���ڸ� �ִ� ���
	}
	return -2;				//��Ƽ���� �̾ƾ��ϴ� ���
}

int choose(int n, int k, int now)
{
	int max = 0;
	int chosen_idx = -1;
	for (int i = 0; i < n; i++) {	//��Ƽ���� ���ڱ���
		int tmpmax = 0;
		for (int j = now; j < k; j++) {	//��Ƽ�ǿ� �ִ� ���ڱ�Ⱑ �̷��� �� ���̴� ���
			if (tab[i] == arr[j]) {	
				tmpmax = j;
				break;				//���� ������ �ִ� �ε����� ������
			}
		}
		if (tmpmax == 0)			//���� ������ �Ⱦ��δٸ� �� ���ڱ���� ��Ƽ�� �ε����� ����
			return i;
		if (max < tmpmax) {			//���� �ڴʰ� ������ϴ� ���ڱ���� �ε��� ������
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
		if (check(arr[i], n) == -1)	//�̹� �����ִ� ���
			continue;
		if (check(arr[i], n) >= 0) {	//���ڸ� �ִ� ���
			int idx = check(arr[i], n);
			tab[idx] = arr[i];
			continue;
		}
		int idx;				
		idx = choose(n, k, i);		//��Ƽ�ǿ� �ٲ㲸�� �ϴ� ���
		tab[idx] = arr[i];			//choose()���� �޾ƿ� ��Ƽ���ε����� ���ο� ���ڱ�� ����
		ans++;					//�ٲ㳤 Ƚ�� ����
	}
	printf("%d\n", ans);
	return 0;
}