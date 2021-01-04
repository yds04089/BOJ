#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

struct Trie {
	bool finish;
	Trie* next[26];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {		//문자열 끝나는 지점인 경우
			finish = true;
		}
		else {
			int index = *key - 'a';
			if (next[index] == NULL) {
				next[index] = new Trie();
			}
			next[index]->insert(key + 1);
		}
	}
	int find(const char* key, int cnt) {
		if (*key == '\0')	//문자열이 끝나는 지점인 경우
			return cnt;
		int index = *key - 'a';
		if (cnt == 0)
			return next[index]->find(key + 1, cnt + 1);
		int check = 0;
		for (int i = 0; i < 26; i++)
			if (next[i] != NULL)
				check++;
		if (check > 1 || finish == true)	//가는길이 두개 이상인 경우
			cnt++;
		return next[index]->find(key + 1, cnt);
	}
};


int main()
{
	int t;
	while (1) {
		cin >> t;
		if (cin.eof())
			break;
		Trie* root = new Trie();
		int sum = 0;
		vector<string> arr(t);

		for (int i = 0; i < t; i++) {
			bool check = true;
			char str[81];
			cin >> arr[i];
			root->insert(arr[i].c_str());
		}
		
		for (int i = 0; i < t; i++) {
			sum += root->find(arr[i].c_str(), 0);
		}
		printf("%.2f\n", double(sum) / double(t));

		delete root;
	}
	return 0;
}