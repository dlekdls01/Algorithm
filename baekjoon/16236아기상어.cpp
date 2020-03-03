#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
/// 자신보다큰물고기 이동불가
/// 자신보다작은물고기 먹을수있
/// 크기같은물고기 이동동만가능
/// 가장가까운 물고기먼저 먹는다
/// 상어크기의물고기 수 를먹으면 상어크기+1
/// 처음상어 크기2

*/



int n;
int map[22][22];
int visit[22][22];
int fish[7] = { 0 };
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
struct ST
{
	int x, y;
	int size;
	int eat;
	int time;
};

bool check(int size) {
	size = min(size, 7);
	int num = 0;
	for (int i = 1; i < size; i++) {
		num += fish[i];
	}
	if (num == 0)return true;
	else return false;
}
int main() {
	int x, y;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				x = i;
				y = j;
				map[i][j] = 0;
			}
			else if (map[i][j] > 0 && map[i][j] < 7)
				fish[map[i][j]]++;
		}
	}

	/////
	int anw = 0;
	int tx, ty;
	ST now, next, temp;
	queue<ST> q;
	now = { x,y,2,0,0 };	//x,y, size, eat갯수, time
	q.push(now);
	visit[x][y] = -1;

	while (!q.empty())
	{
		now = q.front();
		q.pop();


		if (map[now.x][now.y] < now.size && map[now.x][now.y] != 0) {
			while (!q.empty())
			{
				temp = q.front();
				q.pop();
				if (map[temp.x][temp.y] < now.size && map[temp.x][temp.y] !=0) {
					if (temp.time <= now.time) {
						if (now.x > temp.x) {
							now = temp;
						}
						else if (now.x == temp.x) {
							if (now.y > temp.y)
								now = temp;
						}
					}
				}
			}
			//
			now.eat++;
			if (now.size == now.eat) {
				now.eat = 0;
				now.size++;
			}
			anw = now.time;

			//fish갯수-1
			fish[map[now.x][now.y]]--;
			//먹을수있는물고기없을때
			if (check(now.size)) {
				cout << anw << endl;
				return 0;
			}

			fill_n(&visit[0][0], 22 * 22, 0);
			map[now.x][now.y] = 0;
			visit[now.x][now.y] = -1;
			q.push(now);
		}

		for (int i = 0; i < 4; i++) {
			tx = now.x + dx[i];
			ty = now.y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n)continue;
			if (visit[tx][ty] == -1) continue;
			if (now.size < map[tx][ty]) continue;

			//먹을수없고이동만
			if (now.size >= map[tx][ty] ) {
				visit[tx][ty] = -1;
				next = { tx, ty, now.size, now.eat, now.time + 1 };
				q.push(next);
			}

		}
	}
	cout << anw;
	return 0;
}
