#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
struct ST {
	int x, y;
	int dir;  // 0:세로(x+1,y) , 2:가로(x,y+1)
	int depth;
};
int visit[101][101][4];
int dx[4] = { 1,-1, 0,0 };
int dy[4] = {0,0,1,-1 };
vector<vector<int>> map;
int n;

bool check(queue<ST> &q, int x, int y, int dir, int depth) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	if (x + dx[dir] < 0 || x + dx[dir] >= n || y + dy[dir] < 0 || y + dy[dir] >= n) return false;
	if (map[x][y] == 1 || map[x + dx[dir]][y + dy[dir]] == 1) return false;
	if (visit[x][y][dir]) return true;

	visit[x][y][dir] = 1;
	q.push({ x,y,dir, depth + 1 }); 
	return true;
}

int fuc() {
	queue<ST> q;
	ST now;
	int x, y;

	visit[0][0][2] = 1;
	now = { 0,0, 2, 0 };
	q.push(now);
	
	while (!q.empty())
	{
		now = q.front();
		q.pop();
        
		if (now.x == n - 1 && now.y == n - 1) return now.depth;
		if (now.x + dx[now.dir] == n - 1 && now.y + dy[now.dir] == n - 1) return now.depth;

		//세로로 있는경우
		if (now.dir < 2) {
			for (int i = 0; i < 4; i++) {
				x = now.x + dx[i];
				y = now.y + dy[i];
				if (check(q, x, y, 0, now.depth)) {
                    //회전
					if (i == 2) {
						check(q, now.x, now.y, 2, now.depth);
						check(q, now.x + 1, now.y, 2, now.depth);
					}
					else if (i == 3) {
						check(q, x, y, 2, now.depth);
						check(q, x + 1, y, 2, now.depth);
					}
				}
			}
		}
		//가로로 있는 경우
		else {
			for (int i = 0; i < 4; i++) {
				x = now.x + dx[i];
				y = now.y + dy[i];
				if (check(q, x, y, 2, now.depth)) {
                    //회전
					if (i == 0) {
						check(q, now.x, now.y, 0, now.depth);
						check(q, now.x, now.y + 1, 0, now.depth);
					}
					else if (i == 1) {
						check(q, x, y, 0, now.depth);
						check(q, x, y + 1, 0, now.depth);
					}
				}
			}
		}
	}

	return -1;
}

int solution(vector<vector<int>> board) {
	map = board;
	n = board.size();
	int answer = fuc();
	return answer;
}
