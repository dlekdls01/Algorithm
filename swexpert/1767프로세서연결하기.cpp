#include<iostream>
#include<vector>
using namespace std;

int n;
int map[13][13] = { 0, };
vector<pair<int, int>> core;
int dx[4] = { 0,0,-1,1 };		//좌 우 위 밑
int dy[4] = { -1,1,0,0 };
int anw = 987654321;
int conN = 0;
bool flag = false;
bool check(int x, int y, int dir) {
	while (true)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= n || y < 0 || y >= n) return true;
		if (map[x][y] != 0) return false;
		
	}
	return false;
}
int set(int x, int y, int dir, int val) {
	int cnt = 0;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= n) return cnt;
		map[x][y] = val;
		cnt++;
	}
	return 0;
}
void f(int idx, int len, int con) {
	int cnt;
	
	if (idx >= core.size()) {
		if (conN < con) {
			conN = con;
			anw = len;
		}
		else if (conN == con) {
			if (anw > len)
				anw = len;
		}
		return;
	}

	
	flag = false;
	for (int i = 0; i < 4; i++) {
		if (check(core[idx].first, core[idx].second, i)) {
			flag = true;
			cnt = set(core[idx].first, core[idx].second, i, 2);
			f(idx + 1, len + cnt, con+1);
			set(core[idx].first, core[idx].second, i, 0);
		}
	}
	//if(!flag)
		f(idx + 1, len, con);
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		anw = 987654321;
		conN = 0;
		core.clear();
		fill_n(&map[0][0], 13 * 13, 0);
		cin >> n;
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
					core.push_back(make_pair(i, j));
				}
			}
		}
		/////////

		f(0, 0, 0);
		cout << "#" << t << " " << anw << endl;
	}
	return 0;
}
