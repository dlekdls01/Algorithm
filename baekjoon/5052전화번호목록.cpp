#include<iostream>
#include <cstring>
using namespace std;

/*
Trie
# 숫자탐색이라면 next배열사이즈 = 10
# 알파벳(소문자)탐색이라면 next배열사이즈 = 26
# 트리의 depth = 문자열길이
# n길이의 문자열 탐색 시간복잡도 = O(n)

char * key = "123"
# key = 123
# *key = 1 (=key[0])
*/
#define NUMBER 10
struct Trie {
	bool isEnd;
	Trie * next[NUMBER];

	Trie() :isEnd(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i])
				delete next[i];
		}
	}

	//문자열끝이면(\0) true 그렇지않으면 next생성하여넣어줌//
	void insert(char *key) {
		if (*key == NULL)
			isEnd = true;
		else {
			int index = *key - '0';
			if (next[index] == NULL) {
				next[index] = new Trie();
			}
			next[index]->insert(key + 1);
		}
	}


	//트라이에 문자가있으면 true 없으면 false//
	bool find1(char *key) {
		int index = *key - '0';
		if (next[index] == NULL)
			return false;
		else
			return true;
	}

	bool find2(char *key) {
	//문자가 포함관계에 있으면 true그렇지 않으면(leaf에있으면) false// 
		if (*key == NULL)
			return false;
		if (isEnd)
			return true;

		int index = *key - '0';
		return next[index]->find2(key + 1);
	}

};

int main() {

	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n;
		char phone[10001][11];
		Trie *root = new Trie();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> phone[i];
			root->insert(phone[i]);			
		}

		bool is_valid = true;
		for (int i = 0; i < n; i++) {
			if (root->find2(phone[i]) == true) {
				is_valid = false;
				break;
			}
		}

		delete root;
		if (is_valid)
			cout << "YES\n";
		else
			cout << "NO\n";


	}
	return 0;
}
