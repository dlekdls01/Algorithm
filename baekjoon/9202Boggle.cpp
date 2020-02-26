#include<iostream>
#include <cstring>
#include <string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


#define NUMBER 10
#define ALPHABET 26

int w, b;
string boggle[4];

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,1,-1,1,-1 };
int visit[4][4];
set<string> anw;
struct Trie {
	bool isEnd;
	Trie * next[ALPHABET];

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
			int index = *key - 'A';
			if (next[index] == NULL) {
				next[index] = new Trie();
			}
			next[index]->insert(key + 1);
		}
	}


	void find(int x, int y, string key) {
		int tx, ty;

		int index = boggle[x][y] - 'A';
		if (next[index] != NULL && next[index]->isEnd) {
			anw.insert(key);
		}
		if (key.size() >= 8) return;

		for (int c = 0; c < 8; c++) {
			tx = x + dx[c];
			ty = y + dy[c];

			if (tx < 0 || tx>3 || ty < 0 || ty>3) continue;
			if (visit[tx][ty] == -1) continue;

			if (next[index] == NULL) {
				return;
			}
			else {
				visit[tx][ty] = -1;
				key += boggle[tx][ty];
				next[index]->find(tx, ty, key);
				key = key.substr(0, key.size() - 1);
				visit[tx][ty] = 0;
			}
		}
	}

};


int main() {

	Trie *trie = new Trie();
	int score[9] = { 0,0,0,1,1,2,3,5,11 };

	cin >> w;
	for (int i = 0; i < w; i++) {
		char dic[10];
		cin >> dic;
		trie->insert(dic);
	}

	cin >> b;
	for (int t = 0; t < b; t++) {
		for (int i = 0; i < 4; i++)
			cin >> boggle[i];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fill_n(&visit[0][0], 4 * 4, 0);
				int index = boggle[i][j] - 'A';
				if (trie->next[index] == NULL) continue;
				visit[i][j] = -1;
				string key = "";
				key += boggle[i][j];
				trie->find(i, j, key);
			}
		}

		string maxstr = "";
		int sc = 0;
		for (auto str : anw) {
			if (str.size() > maxstr.size()) {
				maxstr = str;
			}
			sc += score[str.size()];
		}
		cout << sc << " " << maxstr << " " << anw.size() << endl;
		anw.clear();
	}


	
	return 0;
}
