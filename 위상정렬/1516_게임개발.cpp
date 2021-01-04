#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;
vector<int> arr[501];
queue<int> q;	//������ ���� Ǯ��ߵǹǷ� priority queue ��
vector<int> tmparr;
int res[501];
int indegree[501];
int time[501];

int tropological(int n)	//��������
{
	for (int i = 1; i <= n; i++)	//indegree�� 0�̸� q�� ����
		if (indegree[i] == 0) {		//res�� time���� ����
			q.push(i);
			res[i] = time[i];	
		}
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.front();
		q.pop();	
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			res[next] = max(res[next], res[now] + time[next]);
				//next�� ������� ������ next������� now������ ������� next�� �ð��� ���� �� �� �� ū�� �ȴ�.
			if (--indegree[next] == 0) {
				q.push(next);
			}		
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
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
		while (1) {
			int num;
			scanf("%d", &num);
			if (num == -1) break;
			arr[num].push_back(i);
			indegree[i]++;
		}
	}		
	int check = tropological(n);
	if (check == 1)
		return 0;
	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}