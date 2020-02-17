#include<iostream>
using namespace std;

int n, h, m;
int map[32][12];
int anw = 10;
bool check() {
	int x;
	for (int i = 1; i <= n; i++) {
		x = i;
		for (int j = 1; j <= h; j++) {
			if (x!=n && map[j][x] == 1) {
				x++;
			}
			else if (x!=1 && map[j][x - 1] == 1) {
				x--;
			}
		}
		if (i != x)
			return false;
	}
	return true;
}
bool flag = false;
void f(int x, int y, int cnt) {
	
	if (x == h + 1)
		return;
	if (anw <= cnt) return;
	if (check()) {
		if (anw > cnt)
			anw = cnt;
		return;
	}
	if (cnt == 3)
		return;

	
	if (y == n)
		f(x + 1, 1, cnt);
	else
		f(x, y + 1, cnt);
	

	if(map[x][y] == 0){
		if (y == 1 && map[x][y+1] == 0) {
			map[x][y] = 1;
			f(x, y + 1, cnt + 1);
			map[x][y] = 0;
		}
		else if (y == n && map[x][y - 1] == 0) {
			map[x][y] = 1;
			f(x + 1, 1, cnt + 1);
			map[x][y] = 0;
		}
		else if(y>1 && y<n) {
			if (map[x][y - 1] == 0 && map[x][y + 1] == 0) {
				map[x][y] = 1;
				if (y == n)
					f(x + 1, 1, cnt + 1);
				else
					f(x, y + 1, cnt + 1);
				map[x][y] = 0;
			}
		}
	}
}
int main() {
	int a, b;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	f(1, 1, 0);
	if (anw == 10) anw = -1;
	cout << anw;
	return 0;
}
