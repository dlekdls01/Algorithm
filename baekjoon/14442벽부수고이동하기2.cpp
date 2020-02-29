#include<iostream>
#include<queue>
using namespace std;

int n, m, k;
char map[1001][1001] = {0, };
int visit[1001][1001][11];

struct ST {
	int x, y;
	int depth;
	int use;
};
int main() {
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	int x, y;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	ST now, next;
	queue<ST> q;
	visit[0][0][0] = 1;
	now = { 0,0,1,0 };
	q.push(now);

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		if (now.x == n - 1 && now.y == m - 1) {
			cout << now.depth;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			x = now.x + dx[i];
			y = now.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;

			if (map[x][y] == '0') {	//벽x
				if (visit[x][y][now.use] == -1)continue;
				visit[x][y][now.use] = -1;
				next = { x,y,now.depth + 1,now.use };
				q.push(next);
			}
			else {				//벽ㅇ
				if (now.use < k) {
					if (visit[x][y][now.use + 1] == -1)continue;
					visit[x][y][now.use+1] = -1;
					next = { x,y,now.depth + 1,now.use+1 };
					q.push(next);
				}
			}
			
			
		}
	}
	cout << "-1";
	return 0;
}
