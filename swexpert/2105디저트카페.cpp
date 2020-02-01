#include<iostream>
using namespace std;

int n;
int map[21][21];
int d[101];		//디저트 선택한종류면 -1
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
int nx, ny;
int anw = -1;

void f(int x, int y, int cnt, int dir) {
	int tx, ty;
	//cout << x << " " << y << " " << cnt << " " << dir <<" "<<map[x][y]<< endl;
	if (nx > x)return;
	if (nx == x && ny == y) {
		if (anw < cnt)
			anw = cnt;
		return;
	}
	
	//같은방향
	tx = x + dx[dir];
	ty = y + dy[dir];
	if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
		if (d[map[tx][ty]] != -1) {
			d[map[tx][ty]] = -1; ;
			f(tx, ty, cnt + 1, dir);
			d[map[tx][ty]] =0;
		}
	}

	//90도꺽기
	dir++;
	if (dir == 4) dir = 0;
	
	tx = x + dx[dir];
	ty = y + dy[dir]; 
	if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
		if (d[map[tx][ty]] != -1) {
			d[map[tx][ty]] = -1; 
			f(tx, ty, cnt + 1, dir);
			d[map[tx][ty]] = 0;
		}
	}
}
int main() {
	int T;
	int tx, ty;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		anw = -1;
		fill_n(d, 101, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				nx = i;
				ny = j;
				tx = nx + dx[0];
				ty = ny + dy[0];
				if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
					d[map[tx][ty]] = -1;
					f(tx, ty, 1, 0);
					d[map[tx][ty]] = 0;
				}
			}
		}
		cout <<"#"<<t<<" "<< anw << endl;
	}
	return 0;
}
