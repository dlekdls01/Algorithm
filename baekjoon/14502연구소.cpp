#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int map[9][9], tmp[9][9];
int anw = 0;
int bfs() {
	int arr[9][9];
	vector<pair<int,int>>v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[i][j];
			if (arr[i][j] == 2)
				v.push_back(make_pair(i,j));
		}
	}

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	int x, y, tx, ty;

	for (int i = 0; i < v.size(); i++) {
		queue<pair<int, int>> q;
		q.push(make_pair(v[i].first, v[i].second));

		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				tx = x + dx[j];
				ty = y + dy[j];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m)	continue;
				if (arr[tx][ty] != 0)	continue;

				arr[tx][ty] = 2;
				q.push(make_pair(tx,ty));
			}
		}
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				num++;
		}
	}

	
	return num;
}
void f(int x, int y, int num) {
	int tx = x;
	int ty = y;

	if (num == 3) {
		int val = bfs();
		if (anw < val)
			anw = val;
		return;
	}

	ty++;
	if (ty == m ) {
		ty = 0;
		tx++;
		if (tx == n)
			return;
	}

	if (tmp[tx][ty] == 0) {
		tmp[tx][ty] = 1;
		f(tx, ty, num + 1);
		tmp[tx][ty] = 0;
	}
	f(tx, ty, num);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			tmp[i][j] = map[i][j];
		}
	}
	f(0, -1, 0);
	cout << anw;
	return 0;
}
