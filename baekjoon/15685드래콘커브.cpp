#include<iostream>
#include<vector>
using namespace std;

/*
///  0 / 1 / 21 / 2321 / 23032321
*/

int map[101][101] = { 0, };
int main() {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,-1,0,1 };
	int x, y, d, g;
	int tx, ty;
	int num;
	vector<int>v;
	int T;
	cin >> T;

	///드래곤커브갯수
	for (int t = 1; t <= T; t++) {
		cin >> x >> y >> d >> g;
		v.clear();
		v.push_back(d);		//선분의 방향 저장

		map[y][x] = 1;		//처음시작점
		x = x + dx[d];		//처음끝점
		y = y + dy[d];
		map[y][x] = 1;

		///g세대
		for (int i = 0; i < g; i++) {	
			int len = v.size()-1;
			for (int j = len; j >=0; j--) {
				num = (v[j] + 1) % 4;
				v.push_back(num);

				x = x + dx[num];
				y = y + dy[num];
				map[y][x] = 1;
			}
		}
		
	}
	int anw = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				anw++;
			}
		}
	}
	cout << anw;
	return 0;
}
