#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

vector <int> arr[10];	//���� ����
int indegree_s[10];
int indegree_b[10];
priority_queue<int, vector<int>, greater<int>> pq_small;
priority_queue<int> pq_big;		
int result_small[10];
int result_big[10];
int ans_small[10];
int ans_big[10];

void tropological_s(int n)	//�ּڰ��� ã������ ��������
{
	for (int i = 0; i <= n; i++) {
		if (pq_small.empty()) return;
		int now_small = pq_small.top();	//ť���ִ� �� �� �ּڰ� ã���� pq��
		pq_small.pop();
		result_small[i] = now_small;
		for (int j = 0; j < arr[now_small].size(); j++)	
			if (--indegree_s[arr[now_small][j]] == 0)	//�̾��� ����� indegree 0�� ��� pq�� ����
				pq_small.push(arr[now_small][j]);
	}
}

void tropological_b(int n)	//�ִ��� ã������ ��������
{
	for (int i = 0; i <= n; i++) {
		if (pq_big.empty()) return;
		int now_big = pq_big.top();	//ť�� �� �� �ִ� ã���� pq��
		pq_big.pop();
		result_big[i] = now_big;
		for (int j = 0; j < arr[now_big].size(); j++)
			if (--indegree_b[arr[now_big][j]] == 0)	//�̾��� ����� indegree 0�� ��� pq�� ����
				pq_big.push(arr[now_big][j]);
	}
}

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		char str;
		cin >> str;
		if (str == '<')		//'<'�̸� ���ʳ�忡 �����ʳ�带 ����
			arr[i].push_back(i + 1);
		else if (str == '>')	//'>'�̸� �����ʳ�忡 ���ʳ�带 ����
			arr[i + 1].push_back(i);
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			indegree_s[arr[i][j]]++;
			indegree_b[arr[i][j]]++;
		}
	}
	for (int i = 0; i <= k; i++) {	//indegree�� 0�� ���� ����pq�� ����
		if (indegree_s[i] == 0) 
			pq_small.push(i);
		if (indegree_b[i] == 0) 
			pq_big.push(i);
	}
	tropological_s(k);		//���� ��������
	tropological_b(k);
	for (int i = 0; i <= k; i++) {	//result������ �ִ�/�ּҰ� ans�迭�� ����
		int idx_small = result_small[i];
		int idx_big = result_big[i];
		ans_small[idx_small] = i;
		ans_big[idx_big] = i + 9 - k;
	}
	for (int i = 0; i <= k; i++)
		printf("%d", ans_big[i]);
	printf("\n");
	for (int i = 0; i <= k; i++)
		printf("%d", ans_small[i]);
	return 0;
}