#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>
#include<climits>
#include <string>
using namespace std;

map<string, int> m;		//map »ç¿ë

int main()
{
	string str;
	int cnt = 0;
	while (!getline(cin, str).eof()) {
		if (str == "")
			break;
		cnt++;
		m[str]++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		double num;
		num = (double)iter->second / cnt * 100;
		cout << iter->first << ' ' << num << endl;
	}
	return 0;
}