#include<iostream>
#include<queue>
using namespace std;


int n;
char map[101][101];
int visit[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct ST
{
	int x, y;
	int depth;
};
int bfs(int x, int y) {
	int tx, ty;
	char c = map[x][y];
	visit[x][y] = -1;
	ST now, next;
	queue<ST> q;
	now = { x,y,0 };
	q.push(now);

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			tx = now.x + dx[i];
			ty = now.y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (visit[tx][ty] == -1) continue;
			if (map[tx][ty] != c) continue;

			visit[tx][ty] = -1;
			next = { tx,ty, now.depth + 1 };
			q.push(next);
		}
	}
	return 1;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int anw = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1) continue;
			anw += bfs(i, j);
		}
	}
	cout << anw << " ";
	////

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R')
				map[i][j] = 'G';
		}
	}
	anw = 0;
	fill_n(&visit[0][0], 101 * 101, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1) continue;
			anw += bfs(i, j);
		}
	}
	cout << anw ;
	return 0;
}
