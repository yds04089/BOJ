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
		max_n = max(max_n, d);	//n�� d�� �ִ밪���� ���� �� �ֱ� ������ d�� �ִ� ã��
	}
	for (int i = 1; i <= max_n; i++) {
		if (arr[i].size() == 1 || arr[i].empty() == 1) continue;	//������ ��ų� �ϳ����̸� ����
		for (int j = 0; j < arr[i].size(); j++) {
			pq.push(arr[i][j]);		//���� d�� ���� �� �ִ� ã������ pq�� �� �־���
		}
		arr[i][0] = pq.top();	//�ִ񰪸� ����
		pq.pop();
		while (!pq.empty()) {
			int now = pq.top();		//d�� �ִ� �ִ��� ������ �ٸ� ������
			pq.pop();
			int min = INF;
			int min_x = INF;
			for (int j = 1; j < i; j++) {	//d���� �����ð� ���� �͵鸸 Ž��
				if (arr[j].empty() == 1) {	//������ �ȵ���ִ� d�� ���
					min = 0;
					min_x = j;
				}
				else if (min > arr[j][0]) {	//d���� �պκ� �� �ּڰ� ã��
					min = arr[j][0]; 
					min_x = j;
				}
			}
			if (min == 0) arr[min_x].push_back(now);	//���� �� �κ� ������ �ű⿡ pq���� ���� �� ����
			else if (min < now) arr[min_x][0] = now;	//�ּڰ����� pq���� ���� ���� �� ������ �� �ڸ��� ����
		}
	}
	int ans = 0;
	for (int i = 1; i <= max_n; i++) {
		if (arr[i].empty()) continue;	//����ִ� ���� ����
		ans += arr[i][0];
	}
	printf("%d\n", ans);
	return 0;
}