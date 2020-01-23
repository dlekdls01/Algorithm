#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int n;
int map[101][101];
int visit[101][101][4];
vector<pair<int,int>> pos[11];	//인덱스에 위치값들어잇슴
int dx[4] = { 0,0,-1, 1 };	//좌 우 위 아래
int dy[4] = { -1,1,0,0 };
int block[5][4] = { {2,0,3,1},{3,0,1,2},{1,3,0,2},{1,2,3,0},{1,0,3,2} };
int anw = 0;
bool flag = false;
void f(int x, int y, int d, int score) {
	//cout << x << " " << y << " " << d << " " << score << endl;
	int dir;
	int num;
	int tx, ty;
	tx = x + dx[d];
	ty = y + dy[d];
	num = map[tx][ty];
	
	

	//벽
	if (tx < 0 || tx >= n || ty < 0 || ty >= n) {
		if (map[x][y] == -2) {
			if (anw < score)
				anw = score;
			return;
		}
		else {
			if (anw < score * 2 + 1)
				anw = score * 2 + 1;
			return;
		}
	}
	//빈공간
	else if (num == 0) {
			f(tx, ty, d, score);
	}
	//자기만나거나 블랙홀
	else if (num == -2 || num == -1) {
		//flag = true;
		if (anw < score)
			anw = score;
		return;
	}
	//블록
	else if (num >= 1 && num <= 4) {
		dir = block[num - 1][d];
			f(tx, ty, dir, score + 1);
	}
	else if (num == 5) {
		//flag = true;
		if (anw < score * 2 + 1)
			anw = score * 2 + 1;
		return;
	}
	//웜홀
	else if (num >= 6 && num <= 10) {
		int idx=-1;
		for (int i = 0; i < 2; i++) {
			if (tx == pos[num][i].first && ty == pos[num][i].second) {
				idx = 1 - i;
				break;
			}
		}
			f(pos[num][idx].first, pos[num][idx].second, d, score);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		anw = 0;
		for (int i = 0; i < 11; i++) {
			pos[i].clear();
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];

				if (map[i][j] > 5) { //웜홀위치와 인덱스저장
					pos[map[i][j]].push_back(make_pair(i, j));	
				}
			}
		}
		//////////
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) continue;
				map[i][j] = -2;
				for (int d = 0; d < 4; d++) {
					visit[i][j][d] = -1;
					f(i, j, d, 0);
				}
				map[i][j] = 0;
			}
		}
	}
	return 0;
}
