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
int res[1001];		//�����
int indegree[1001];
int maxnum[1001][2];	//�� ��庰 <�ִ�, �ִ��� ����>

int tropological(int n)	//��������
{
	for (int i = 1; i <= n; i++)	//indegree�� 0�̸� q�� ����
		if (indegree[i] == 0) {		
			q.push(i);
			res[i] = 1;				//res���� 1 ����
			maxnum[i][0] = 1;
			maxnum[i][1] = 1;
		}
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.front();
		q.pop();
		if (maxnum[now][1] > 1) {	//pop�ؼ� ���� ����� �ִ񰪰����� 2�̻��̸� �ִ� 1����
			maxnum[now][0]++;
			maxnum[now][1] = 1;
		}
		res[now] = maxnum[now][0];
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (maxnum[next][0] == 0) {	//next �������� 0�� ���
				maxnum[next][0] = maxnum[now][0];
				maxnum[next][1] = 1;
			}
			else if (maxnum[next][0] == maxnum[now][0]) {	//next�� �ִ��� now�ִ�� �������
				maxnum[next][1]++;
			}
			else if (maxnum[next][0] < maxnum[now][0]) {	//now�ִ��� next���� ū ���
				
				maxnum[next][0] = maxnum[now][0];
				maxnum[next][1] = 1;
			}
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
		int k, m, p; 
		scanf("%d %d %d", &k, &m, &p);
		for (int i = 0; i <= m; i++) {	//test case�������̹Ƿ� �Ź� �ʱ�ȭ
			arr[i].clear();
			res[i] = 0;
			indegree[i] = 0;
			maxnum[i][0] = 0;
			maxnum[i][1] = 0;
		}
		for (int i = 1; i <= p; i++) {
			int n1, n2;
			scanf("%d%d", &n1, &n2);
			arr[n1].push_back(n2);
			indegree[n2]++;
		}
		int check;
		check = tropological(m);	//��������
		if (check == 1)
			return 0;
		printf("%d %d\n", k, res[m]);
	}
	return 0;
}