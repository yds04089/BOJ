#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[1001];
queue<int> q;
vector<int> tmparr;
int res[1001];
int indegree[1001];

int tropological(int n)	//��������
{
	for (int i = 1; i <= n; i++)	//indegree�� 0�̸� q�� ����
		if (indegree[i] == 0)
			q.push(i);
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.front();
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
		int num;
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			int tmp;
			scanf("%d", &tmp);
			tmparr.push_back(tmp);
		}
		for (int i = 0; i < num-1; i++) {
			int now = tmparr[i];
			int next = tmparr[i + 1];
			indegree[next]++;
			arr[now].push_back(next);
		}
		tmparr.clear();
	}
	int check = tropological(n);
	if (check == 1) {	//����Ŭ �ִ� ���
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++)	//����Ŭ ���� ���
		printf("%d\n", res[i]);
	return 0;
}