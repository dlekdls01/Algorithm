#include<iostream>
#include<queue>
using namespace std;

int main() {
	int map[51][51];
	int check[51][51];
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int T;
	int n, m, r, c, l;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> r >> c >> l;

		fill_n(&map[0][0], 51 * 51, 0);
		fill_n(&check[0][0], 51 * 51, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}

		queue<pair<int, int>> q;
		q.push(make_pair(r, c));
		check[r][c] = 1;
		int x=0, y=0, tx=0, ty=0;
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			if (check[tx][ty] > l)
				break;
			
			for (int i = 0; i < 4; i++) {		//0:상 1:하 2:좌 3:우
				switch (map[x][y])
				{
				case 1:
					break;
				case 2:
					if (i == 2 || i == 3) continue;
					break;
				case 3:
					if (i == 0 || i == 1) continue;
					break;
				case 4:
					if (i == 1 || i == 2) continue;
					break;
				case 5:
					if (i == 0 || i == 2) continue;
					break;
				case 6:
					if (i == 0 || i == 3) continue;
					break;
				case 7:
					if (i == 1 || i == 3) continue;
					break;
				}
				tx = x + dx[i];
				ty = y + dy[i];

				if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
				if (check[tx][ty] > 0) continue;
				if (map[tx][ty] == 0) continue;

				switch (map[tx][ty])	//0:상 1:하 2:좌 3:우
				{
				case 1:
					break;
				case 2:
					if (i == 2 || i == 3) continue;
					break;
				case 3:
					if (i == 0 || i == 1) continue;
					break;
				case 4:
					if (i == 0 || i == 3) continue;
					break;
				case 5:
					if (i == 1 || i == 3) continue;
					break;
				case 6:
					if (i == 1 || i == 2) continue;
					break;
				case 7:
					if (i == 0 || i == 2) continue;
					break;
				}

				check[tx][ty] = check[x][y] + 1;
				q.push(make_pair(tx, ty));
			}
		}
		int anw = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] > 0 && check[i][j] <= l)
					anw++;
			}
		}
		cout << "#" << t << " " << anw << endl;
	}
	return 0;
}
