#include<iostream>
#include<vector>
using namespace std;

int n, k;
int anw = 0;
int map[9][9];
int visit[9][9];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void f(int x, int y, int depth, bool flag) {
	int tx, ty;
	int temp, tk;
	if (anw < depth)
		anw = depth;

	for (int i = 0; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
			if (visit[tx][ty] != -1) {
				if (map[x][y] > map[tx][ty]) {
					visit[tx][ty] = -1;
					f(tx, ty, depth + 1, flag);
					visit[tx][ty] = 0;
				}
				else {
					if (!flag) {
						temp = map[tx][ty];
						tk = k;
						while (tk >0) {
							map[tx][ty] = map[tx][ty] - tk;
							if (map[x][y] > map[tx][ty]) {
								visit[tx][ty] = -1;
								f(tx, ty, depth + 1, true);
								visit[tx][ty] = 0;
							}
							map[tx][ty] = temp;
							tk--;
						}
					}
				}
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int max = 0;
		vector<pair<int, int>> start;
		anw = 0;
		fill_n(&map[0][0], 9 * 9, 0);
		fill_n(&visit[0][0], 9 * 9, 0);

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (max < map[i][j]) {					//max값과 위치 저장
					max = map[i][j];
					start.clear();
					start.push_back(make_pair(i, j));
				}
				else if (max == map[i][j]) {
					start.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < start.size(); i++) {
			fill_n(&visit[0][0], 9 * 9, 0);
			visit[start[i].first][start[i].second] = -1;
			f(start[i].first, start[i].second, 1, false);
		}
		cout <<"#"<<t<<" "<< anw << endl;
	//////
	}
}
