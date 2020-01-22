#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define TESTCASE 10
#define N 16

struct ST
{
	int x, y;
};

char map[100][100];
int visit[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool isConnect(int st_x, int st_y) {
	queue<ST> q;
	ST now;
	int x, y;
	q.push({ st_x, st_y });
	visit[st_x][st_y] = -1;

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			x = now.x + dx[i];
			y = now.y + dy[i];

			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (map[x][y] == '1')continue;
			if (visit[x][y] == -1)continue;

			if (map[x][y] == '3') return true;

			visit[x][y] = -1;
			q.push({ x,y });
		}
	}
	return false;
}
int main() {
	int t;
	int st_x, st_y;

	for (int t = 1; t <= TESTCASE; t++) {	
		cin >> t;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == '2') {
					st_x = i; st_y = j;
				}
			}
		}
		if (isConnect(st_x, st_y))
			cout << "#" << t << " " << "1\n";
		else
			cout << "#" << t << " " << "0\n";
		fill_n(&visit[0][0], 100 * 100, 0);
	}
	return 0;
}
