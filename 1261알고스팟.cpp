#include <iostream>
#include <vector>
#include<math.h>
#include<queue>
#include <functional>
using namespace std;

#define INF 987654321

struct ST {
	int x, y;
	int cost;
};
struct cmp {
	bool operator()(ST a, ST b){
		if (a.cost > b.cost) return true;
		else if (a.cost == b.cost) return a.x > b.x;
		else return false;
	}
};
int n, m;
char map[101][101];
int visit[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//
	priority_queue<ST, vector<ST>, cmp> pq;
	ST now, next;
	fill_n(&visit[0][0], 101 * 101, INF);
	now = { 0,0,0 };
	visit[0][0] = 0;
	pq.push(now);
	int x, y, val;

	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			x = now.x + dx[i];
			y = now.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)continue;

			if (map[x][y] == '0') val = 0;
			else val = 1;

			if (visit[x][y] > visit[now.x][now.y] + val) {
				visit[x][y] = visit[now.x][now.y] + val;
				next = { x,y, visit[x][y] };
				pq.push(next);
			}
		}
	}
	cout << visit[n - 1][m - 1];
	return 0;
}
