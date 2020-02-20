#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
int map[9][9];
vector<pair<int, int>> c;
string d1 = "ruld", d2 = "rlud", d3 = "ruullddr", d4 = "rululdldrrud", d5 = "ruld";
int anw = 10000000;


void copyArr(int (*a)[9], int (*b)[9]) {		//a->b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
		}
	}
}
void check(int x, int y, char d, int(*arr)[9]) {	//r,l,u,d 쭉채우기

	if (d == 'u') {
		for (int i = x-1; i >= 0; i--) {
			if (map[i][y] == 6)	return;
			if (map[i][y] == 0)	arr[i][y] = 9;
		}
	}
	else if (d == 'd') {
		for (int i = x+1; i < n; i++) {
			if (map[i][y] == 6)	return;
			if (map[i][y] == 0)	arr[i][y] = 9;
		}
	}
	else if (d == 'l') {
		for (int i = y-1; i >= 0; i--){
			if (map[x][i] == 6)	return;
			if (map[x][i] == 0) arr[x][i] = 9;
		}
	}
	else if (d == 'r') {
		for (int i = y+1; i < m; i++) {
			if (map[x][i] == 6) return;
			if (map[x][i] == 0) arr[x][i] = 9;
		}
	}
}
void pr() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j]<<" ";
		}cout << endl;
	}
}
void f(int idx) {
	int temp[9][9];
	copyArr(map, temp);

		//pr();

	///카메라다감시한경우
	if (idx >= c.size()) {
	
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0)
					num++;
			}
		}
		if (anw > num)
			anw = num;
		return;
	}

	int x = c[idx].first;
	int y = c[idx].second;
	int type = map[x][y];
	char c;
	int re=0;
	switch (type)
	{
	case 1:
		for (int i = 0; i < d1.size(); i++) {
			c = d1[i];
			check(x, y, c, map);
			f(idx + 1);
			copyArr(temp, map);
		}
		break;
	case 2:
		for (int i = 0; i < d2.size(); i++) {
			c = d2[i];
			check(x, y, c, map); 
			re++;
			if (re == 2) {
				f(idx + 1);
				copyArr(temp, map);
				re = 0;
			}
		}
		break;
	case 3:
		for (int i = 0; i < d3.size(); i++) {
			c = d3[i];
			check(x, y, c, map); 
			re++;
			if (re == 2) {
				f(idx + 1);
				copyArr(temp, map);
				re = 0;
			}
		}
		break;
	case 4:
		for (int i = 0; i < d4.size(); i++) {
			c = d4[i];
			check(x, y, c, map); 
			re++;
			if (re == 3) {
				f(idx + 1);
				copyArr(temp, map);
				re = 0;
			}
		}
		break;
	case 5:
		for (int i = 0; i < d5.size(); i++) {
			c = d2[i];
			check(x, y, c, map);
		}
		f(idx + 1);
		copyArr(temp, map);
		break;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				c.push_back(make_pair(i, j));
		}
	}
	
	
	f(0);
	cout << anw;
	return 0;
}
