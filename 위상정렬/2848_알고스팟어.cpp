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


int tropological(int n)	//위상정렬
{
	int isOrder = 0;
	for (int t = 0; t < num.size(); t++) {	//num배열을 이용해서 indegree가 0인지 체크
		if (indegree[num[t]] == 0) {		//indegree가 0이면 q에 삽입
			q.push(num[t]);
		}
	}
	int idx = 0;
	while (!q.empty()) {		//q가 빌때까지
		int now = q.front();
		res[idx] = now;
		if (q.size() > 1)		//q에 한번에 여러개 들어가 있는 경우 (결과값이 여러가지됨)
			isOrder = 1;;
		q.pop();
		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (--indegree[next] == 0)
				q.push(next);
		}
		idx++;
	}
	if (idx != num.size())	//사이클 있는 경우
		return 1;
	else if (isOrder == 1)	//여러가지 경우의수 있는 경우
		return 2;
	else			//사이클 없는 경우
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
			tmp[i][j] = s[i][j] - 'a';	//알파벳을 숫자로 변환
			int isIn = 0;
			for (int t = 0; t < num.size(); t++) {	//서로다른 알파벳들을 num배열에 삽입
				if (num[t] == tmp[i][j])
					isIn = 1;
			}
			if (isIn == 0)
				num.push_back(tmp[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {	//바로 위, 아래의 단어에서 다른 부분 나오면 arr배열로 연결시킴
		int minsize = min(strSizes[i - 1], strSizes[i]);
		for (int j = 0; j < minsize; j++) {
			if (tmp[i - 1][j] != tmp[i][j]) {
				arr[tmp[i - 1][j]].push_back(tmp[i][j]);
				indegree[tmp[i][j]]++;
				break;
			}
			if (j == minsize - 1 && strSizes[i - 1] > strSizes[i]) {	//애초에 입력이 사전순이 아닌 경우
				printf("!\n");
				return 0;
			}
		}
	}
	int arrsize = num.size();	//전체 알파벳 개수 == num배열의 크기
	int check;
	check = tropological(arrsize);	//위상정렬
	if (check == 1)
		printf("!");
	else if (check == 0) 
		for (int i=0; i<arrsize; i++)
			printf("%c", res[i]+'a');	//결과값을 다시 알파벳으로 변환
	else
		printf("?");
	printf("\n");

	return 0;
}