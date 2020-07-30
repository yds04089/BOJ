#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<string.h>
#include<limits.h>
using namespace std;
vector<int> arr[101];
queue<int> q;	
int res[101];	
int indegree[101];
char s[100][100];
int tmp[101][101];
vector<int> num;
int strSizes[100];


int tropological(int n)	//��������
{
	int isOrder = 0;
	for (int t = 0; t < num.size(); t++) {	//num�迭�� �̿��ؼ� indegree�� 0���� üũ
		if (indegree[num[t]] == 0) {		//indegree�� 0�̸� q�� ����
			q.push(num[t]);
		}
	}
	int idx = 0;
	while (!q.empty()) {		//q�� ��������
		int now = q.front();
		res[idx] = now;
		if (q.size() > 1)		//q�� �ѹ��� ������ �� �ִ� ��� (������� ����������)
			isOrder = 1;;
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (--indegree[next] == 0)
				q.push(next);
		}
		idx++;
	}
	if (idx != num.size())	//����Ŭ �ִ� ���
		return 1;
	else if (isOrder == 1)	//�������� ����Ǽ� �ִ� ���
		return 2;
	else			//����Ŭ ���� ���
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int size = strlen(s[i]);
		strSizes[i] = size;
		for (int j = 0; j < size; j++) {
			tmp[i][j] = s[i][j] - 'a';	//���ĺ��� ���ڷ� ��ȯ
			int isIn = 0;
			for (int t = 0; t < num.size(); t++) {	//���δٸ� ���ĺ����� num�迭�� ����
				if (num[t] == tmp[i][j])
					isIn = 1;
			}
			if (isIn == 0)
				num.push_back(tmp[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {	//�ٷ� ��, �Ʒ��� �ܾ�� �ٸ� �κ� ������ arr�迭�� �����Ŵ
		int minsize = min(strSizes[i - 1], strSizes[i]);
		for (int j = 0; j < minsize; j++) {
			if (tmp[i - 1][j] != tmp[i][j]) {
				arr[tmp[i - 1][j]].push_back(tmp[i][j]);
				indegree[tmp[i][j]]++;
				break;
			}
			if (j == minsize - 1 && strSizes[i - 1] > strSizes[i]) {	//���ʿ� �Է��� �������� �ƴ� ���
				printf("!\n");
				return 0;
			}
		}
	}
	int arrsize = num.size();	//��ü ���ĺ� ���� == num�迭�� ũ��
	int check;
	check = tropological(arrsize);	//��������
	if (check == 1)
		printf("!");
	else if (check == 0) 
		for (int i=0; i<arrsize; i++)
			printf("%c", res[i]+'a');	//������� �ٽ� ���ĺ����� ��ȯ
	else
		printf("?");
	printf("\n");

	return 0;
}