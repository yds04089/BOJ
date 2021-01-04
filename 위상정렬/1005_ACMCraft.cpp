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
queue<int> q;	//������ ���� Ǯ��ߵǹǷ� priority queue ��
int res[1001];
int indegree[1001];
int time[1001];

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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k; 
		scanf("%d %d", &n, &k);
		for (int i = 0; i <= n; i++) {	//test case�������̹Ƿ� �Ź� �ʱ�ȭ
			arr[i].clear();
			time[i] = 0;
			res[i] = 0;
			indegree[i] = 0;
		}
		for (int i = 1; i <= n; i++) 
			scanf("%d", &time[i]);
		for (int i = 1; i <= k; i++) {
			int n1, n2;
			scanf("%d%d", &n1, &n2);
			arr[n1].push_back(n2);
			indegree[n2]++;
		}
		int check = tropological(n);	//��������
		if (check == 1)
			return 0;
		int w;
		scanf("%d", &w);
		printf("%d\n", res[w]);
	}
	return 0;
}