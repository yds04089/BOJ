#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<stdlib.h>
using namespace std;

string s1, s2, s3;
int dp[101][101][101];

void LCS(string str1, string str2, string str3) //LCS 알고리즘 (3개를 동시 비교)
{
	int size1 = str1.length();
	int size2 = str2.length();
	int size3 = str3.length();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			for (int k = 0; k < size3; k++) {
				if (str1[i] == str2[j] && str2[j] == str3[k]) 		//공통된 문자인 경우
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else 			//다른 문자인 경우
					dp[i + 1][j + 1][k + 1] = max(max(dp[i + 1][j + 1][k], dp[i + 1][j][k + 1]), dp[i][j + 1][k + 1]);
				
			}
			
		}
	}
}

int main()
{
	cin >> s1 >> s2 >> s3;
	int s1_size = s1.length();
	int s2_size = s2.length();
	int s3_size = s3.length();
	LCS(s1, s2, s3);
	printf("%d\n", dp[s1_size][s2_size][s3_size]);
	return 0;
}