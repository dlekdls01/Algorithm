#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n, m;
int map[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int k[22];
int visit[21][21];

struct ST
{
	int x, y;
	int depth;
};
void bfs(int x, int y) {
	int tx, ty;
	queue<ST>q;
	ST now, next;
	now = { x,y,1 };
	q.push(now);
	visit[x][y] = 1;

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		if (now.depth > n)
			break;

		for (int i = 0; i < 4; i++) {
			tx = now.x + dx[i];
			ty = now.y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n)continue;
			if (visit[tx][ty] != 0) continue;

			visit[tx][ty] = now.depth + 1;
			next = { tx,ty,now.depth + 1 };
			q.push(next);
		}
	}
}

int check() {
	int home[22];	//k범위에들어잇는 집의갯수
	int sum;		//k범위안의 집들이내는 총 서비스비용

	fill_n(&home[0], 22, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j]!=0) {
				home[visit[i][j]]++;
			}
		}
	}
	
	for (int i = 1; i < 22; i++)
		home[i] += home[i - 1];

	for (int i = 21; i >= 1; i--) {
		sum = home[i] * m;
		if (sum >= k[i]) {
			return home[i];
		}
	}
	return 0;
}
int main() {
	int T;
	int anw,num;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		anw = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		k[0] = 0;
		for (int i = 1; i < 22; i++) {
			k[i] = i * i + (i - 1)*(i - 1); ;
		}
		//////
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fill_n(&visit[0][0], 21 * 21, 0);
				bfs(i, j);
				num = check(); 
				if (anw < num)
					anw = num;
			}
		}
		cout <<"#"<<t<<" "<< anw << endl;
	}
	return 0;
}
