#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<pair<int, int>> arr[101];
queue<int> q;	
int need[101][101];		//i�� ����µ� �ʿ��� j�� ���� ����
int indegree[101];
vector<int> basic;		//�⺻��ǰ ����

int tropological(int n)	//��������
{
	for (int i = 1; i <= n; i++)	//indegree�� 0�̸� q�� ����
		if (indegree[i] == 0) {	
			need[i][i] = 1;		//�⺻��ǰ���� Ȯ���� �� ���
			q.push(i);		
			basic.push_back(i);
		}
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.front();
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i].first;
			int cost = arr[now][i].second;
			if (need[now][now] == 1) {	//�⺻��ǰ�϶�
				need[next][now] += cost;
			}
			else {
				for (int i = 1; i <= n; i++) {	//�߰���ǰ�϶�
					if (need[now][i] > 0) {
						need[next][i] += need[now][i] * cost;
					}
				}
			}
			if (--indegree[next] == 0)
				q.push(next);
		}
		idx++;
	}
	if (idx == n)	//������ ������ q�� ������� ����Ŭ ����
		return 0;
	else			//n���� ���� ���� ť�� ��ԵǸ� ����Ŭ ����
		return 1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		arr[y].push_back(make_pair(x, k));
		indegree[x]++;
	}
	int check;
	check = tropological(n);	//��������
	if (check == 1)
		return 0;
	for (int i = 0; i < basic.size(); i++) 
		printf("%d %d\n", basic[i], need[n][basic[i]]);
	return 0;
}