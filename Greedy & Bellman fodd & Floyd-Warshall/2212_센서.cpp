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
priority_queue <int> pq;	//�Ÿ��� �ִ� �̾��ִ� pq

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
	int longdist = arr[n-1] - arr[0];	//���� �Ÿ� �� �� ���� �Ÿ�
	for (int i = 1; i < n; i++) {
		dist[i] = arr[i] - arr[i - 1];
		pq.push(dist[i]);				//�Ÿ��� �ִ� ���Ϸ��� pq�� ����
	}
	int maxsum = 0;
	while (k > 0 && !pq.empty()) {	//pq�� ����� �� ����ó���� ����
		maxsum += pq.top();			//���߱� ����-1�� ��ŭ �Ÿ��ִ� ���ؼ� ���� 
		pq.pop();	
		k--;
	}
	printf("%d\n", longdist - maxsum);	//���� �� �� �����Ÿ� - ���ӵ� �� ������ �Ÿ��� �ִ񰪵��� ��
	return 0;
}