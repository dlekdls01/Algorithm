#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ST
{
	int x, y;	//R위치
	int a, b;	//B위치
	int depth;	//움직인회수
	int dir;	//움직인방향
}typedef ST;
int main() {
	vector<pair<int, int>> v(2);	//R,B위치저장
	int dx[4] = { -1,0,0,1 };		//0:상 1:좌 2:우 3:하
	int dy[4] = { 0,-1,1,0 };
	char map[11][11];
	int visit[11][11][11][11];
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				v[0] = make_pair(i, j);
			else if (map[i][j] == 'B')
				v[1] = make_pair(i, j);
		}
	}
	//
	bool flag = false, goal = false, sam = false;	//B가골에들어갔는가, A가골에들어갔는가, A가지나가는길에B가있엇는가
	int cnt;
	int rx, ry, bx, by;
	ST now, next;
	queue<ST> q;
	now.x = v[0].first;		now.y = v[0].second;
	now.a = v[1].first;		now.b = v[1].second;
	now.depth = 0;
	now.dir = -1;
	visit[now.x][now.y][now.a][now.b] = -1;
	q.push(now);

	while (!q.empty())
	{
		now = q.front();
		q.pop();
		//if (now.depth >= 10) break;		//10번넘어가면 -1

		for (int i = 0; i < 4; i++) {
			if (i == now.dir) continue;			//했던방향으로기울기x
			if (i + now.dir == 3) continue;		//했던방향반대로기울기x
			rx = now.x;		ry = now.y;		//R의위치
			bx = now.a;		by = now.b;		//B의위치
			cnt = 0;
			flag = false;	goal = false;	sam = false;

			//R
			while (true)
			{
				rx = rx + dx[i];	ry = ry + dy[i];
				if (rx < 0 || rx >= h || ry < 0 || ry >= w) break;	//넘어가면break
				if (map[rx][ry] == '#') break;						//벽에다으면break
				if (rx == bx && ry == by) sam = true;				//가는길에B있으면 sam
				if (map[rx][ry] == 'O')	goal = true;				//가는길에goal있으면 goal
			}
			rx = rx - dx[i];	ry = ry - dy[i];					//넘어가거나벽에닿은곳이기때문에 바로전위치로

																	//B
			while (true) {
				bx = bx + dx[i];
				by = by + dy[i];
				if (bx < 0 || bx >= h || by < 0 || by >= w) break;
				if (map[bx][by] == '#') break;
				if (map[bx][by] == 'O') {
					flag = true;
					break;
				}
				if (rx == bx && ry == by && !sam)  break;			//R가닿으면
			}
			bx = bx - dx[i];	by = by - dy[i];

			if (!flag) {		//B가골에안들어갔을경우
				if (goal) {		//R가골에들어갔을경우 -> 답
					cout << now.depth + 1;
					return 0;
				}
				next.x = rx;			next.y = ry;
				next.a = bx;			next.b = by;
				if (sam) {		//R을B의전위치로
					next.x = next.a - dx[i];
					next.y = next.b - dy[i];
				}
				next.depth = now.depth + 1;
				next.dir = i;

				if (visit[next.x][next.y][next.a][next.b] != -1) {
					visit[next.x][next.y][next.a][next.b] = -1;
					q.push(next);
				}
			}
		}
	}
	cout << "-1";
	return 0;
}
