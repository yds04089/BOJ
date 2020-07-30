#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[32001];
priority_queue<int, vector<int>, greater<int>> q;	//������ ���� Ǯ��ߵǹǷ� priority queue ��
vector<int> tmparr;
int res[32001];
int indegree[32001];

int tropological(int n)	//��������
{
	for (int i = 1; i <= n; i++)	//indegree�� 0�̸� q�� ����
		if (indegree[i] == 0)
			q.push(i);
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.top();
		q.pop();
		res[idx++] = now;		//q���� pop�Ǵ� ������� ������� ����
		for (int i = 0; i < arr[now].size(); i++) {
			if (--indegree[arr[now][i]] == 0)	
				q.push(arr[now][i]);
		}
	}
	if (idx == n)	//������ ������ q�� ������� ����Ŭ ����
		return 0;
	else			//n���� ���� ���� ť�� ��ԵǸ� ����Ŭ ����
		return 1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int small, big;
		scanf("%d%d", &small, &big);
		arr[small].push_back(big);
		indegree[big]++;
	}
	int check = tropological(n);
	if (check == 1)
		return 0;
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}