#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> map;
int anw[3] = { 0 };
void pr() {
	cout << "-----\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", map[i][j]);
		}cout << endl;
	}
}

bool check(int a, int b, int c, int d) {
	int x = map[a][b];
	for (int i = a; i < c; i++) {
		for (int j = b; j < d; j++) {
			if (x != map[i][j]) return false;
		}
	}
	return true;
}
void fuc(int a, int b, int c, int d) {
	//check
	if (check(a, b, c, d)) {
		anw[map[a][b] + 1]++;
		return;
	}
	else {
		int num = (c-a) / 3;
		fuc(a, b, a+num, b+num);
		fuc(a + num, b, a + 2 * num, b + num);
		fuc(a + 2 * num, b, c, b + num);

		fuc(a, b + num, a + num, b + 2 * num);
		fuc(a + num, b + num, a + 2 * num, b + 2 * num);
		fuc(a + 2 * num, b + num, c, b + 2 * num);

		fuc(a, b + 2 * num, a + num, d);
		fuc(a + num, b + 2 * num, a + 2 * num, d);
		fuc(a + 2 * num, b + 2 * num, c, d);
	}
}
int main() {
	int x;
	cin >> n;

	map.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			map[i].push_back(x);
		}
	}

	fuc(0, 0, n, n);
	cout << anw[0] << endl;
	cout << anw[1] << endl;
	cout << anw[2] << endl;
	
	return 0;
}
