#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<stdlib.h>
using namespace std;

string s1, s2, s3;
int dp[201][201];

void LCS(string str1, string str2) //LCS 알고리즘 
{
	int size1 = str1.length();
	int size2 = str2.length();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
				if (str1[i] == str2[j]) 		//공통된 문자인 경우
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else 			//다른 문자인 경우
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
}

int main()
{
	while (1) {
		cin >> s1 >> s2;
		if (cin.eof() == true)	//파일의 끝이면 종료시킴
			return 0;
		int s1_size = s1.length();
		int s2_size = s2.length();
		LCS(s1, s2);
		printf("%d\n", dp[s1_size][s2_size]);
		
	}
	return 0;
}