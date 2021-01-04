#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

string s1, s2;
int dp[1001][1001];
int tracking[1001][1001];	//string �ϼ��Ϸ��� ���

void LCS(int size1, int size2) //LCS �˰���
{
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (s1[i] == s2[j]) {		//����� ������ ���
				dp[i + 1][j + 1] = dp[i][j] + 1;
				tracking[i + 1][j + 1] = 1;
			}
			else {			//�ٸ� ������ ���
				if (dp[i + 1][j] > dp[i][j + 1]) {
					dp[i + 1][j + 1] = dp[i + 1][j];
					tracking[i + 1][j + 1] = 2;
				}
				else if (dp[i + 1][j] <= dp[i][j + 1]) {	//�� dp���� ���� ���� ���� �Ʒ� ��� �� �ƹ����� �־��൵��
					dp[i + 1][j + 1] = dp[i][j + 1];
					tracking[i + 1][j + 1] = 3;
				}
			}
		}
	}

}

int main()
{
	string ans = "";
	cin >> s1 >> s2;
	int s1_size = s1.length();
	int s2_size = s2.length();
	LCS(s1_size, s2_size);
	if (dp[s1_size][s2_size] == 0) {
		printf("0\n");
		return 0;
	}
	int n1 = s1_size, n2 = s2_size;
	while (tracking[n1][n2]!=0) {
		if (tracking[n1][n2] == 1) {	//����� ������ ���
			ans += s1[n1-1];			//ans string�� �߰�
			n1--;
			n2--;
		}
		else if (tracking[n1][n2] == 2) {
			n2--;
		}
		else if (tracking[n1][n2] == 3) {
			n1--;
		}
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", dp[s1_size][s2_size]);
	cout << ans;
	return 0;
}