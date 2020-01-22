#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define TESTCASE 10
#define N 100

struct ST
{
	int x, y;
	int cnt;
};
int map[100][100];
int visit[100][100];
int dx[3] = { 0,0,1 };
int dy[3] = { -1,1,0 };

int getDist(int idx) {
	queue<ST> q;
	ST now;
	int tx, ty;
	q.push({ 0,idx,0 });
	visit[0][idx] = -1;

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		if (now.x == N - 1) break;

		for (int i = 0; i < 3; i++) {
			tx = now.x + dx[i];
			ty = now.y + dy[i];

			if (tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
			if (map[tx][ty] == 0) continue;
			if (visit[tx][ty] == -1) continue;

			visit[tx][ty] = -1;
			q.push({ tx,ty,now.cnt + 1 });
			break;
		}
	}
	return now.cnt;
}
int main() {
	int anw, dist, minDist;

	for (int t = 1; t <= TESTCASE; t++) {		
		cin >> anw;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		minDist = INT16_MAX;
		for (int i = 0; i < N; i++) {
			if (map[0][i] == 0)continue;
			fill_n(&visit[0][0], 100 * 100, 0);
			dist = getDist(i);
			if (minDist >= dist) {
				minDist = dist;
				anw = i;
			}
		}
		
		cout << "#" << t << " " << anw << endl;
	}
	return 0;
}
