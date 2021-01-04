#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

char arr[10000][11];

struct Trie {
	bool finish;
	Trie* next[10];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int index = *key - '0';
			if (next[index] == NULL)
				next[index] = new Trie();
			next[index]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0')
			return true;
		if (finish == 1)
			return false;
		int index = *key - '0';
		return next[index]->find(key + 1);
	}
};


int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		Trie* root = new Trie();
		bool check = true;
		for (int i = 0; i < n; i++) {
			scanf("%s", &arr[i]);
			root->insert(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			if (root->find(arr[i]) == false) {
				check = false;
				break;
			}
		}
		delete root;
		if (check == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}