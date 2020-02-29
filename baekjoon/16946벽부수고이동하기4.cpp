#include <iostream>
#include <queue>
#include<vector>
#include<string>
#include<set>
using namespace std;

int n, m;
char map[1001][1001];
int visit[1001][1001];
int anw[1001][1001];
int nums[1111111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct ST {
	int x, y;
};

void pr(int a[1001][1001]) {
	cout << "-----------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}

}
int bfs(int a, int b, int val) {
	visit[a][b] = val;
	ST  now, next;
	queue<ST> q;
	now = { a,b };
	q.push(now);
	int x, y;
	int num = 0;

	while (!q.empty())
	{
		now = q.front();
		q.pop();
		num++;

		for (int i = 0; i < 4; i++) {
			x = now.x + dx[i];
			y = now.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (visit[x][y] > 0) continue;
			if (map[x][y] == '1')continue;
			visit[x][y] = val;
			next = { x,y };
			q.push(next);
		}
	}
	return num;
}
int main() {
	cin >> n >> m;
	vector<pair<int, int>> m0, m1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0')
				m0.push_back(make_pair(i, j));
			if (map[i][j] == '1')
				m1.push_back(make_pair(i, j));
			;
		}
	}

	int num;
	fill_n(&anw[0][0], 1001 * 1001, 0);
	fill_n(&visit[0][0], 1001 * 1001, 0);

	//0인것들 모임 갯수 구하기
	for (int i = 0; i < m0.size(); i++) {
		if (visit[m0[i].first][m0[i].second] == 0) {
			num = bfs(m0[i].first, m0[i].second, i + 1);
			nums[i + 1] = num;
		}
	}
	//pr(visit);
	//1인것을 0로했을때 모임합쳐서 갯수구하기
	int x, y;
	int cnt;
	string str = "";
	string s = "";
	set<int> st;
	for (int i = 0; i < m1.size(); i++) {
		str = "";
		cnt = 1;

		for (int j = 0; j < 4; j++) {
			x = m1[i].first + dx[j];
			y = m1[i].second + dy[j];
			if (x < 0 || x >= n || y < 0 || y >= m)continue;
			if (map[x][y] == '1')continue;

			//s에는 visit값저장중복제외하기위해
			st.insert(visit[x][y]);
		}

		for (auto s = st.begin(); s != st.end(); s++) {
			cnt += nums[*s];
		}
		st.clear();
		anw[m1[i].first][m1[i].second] = cnt % 10;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << anw[i][j];
		}cout << endl;
	}
	return 0;
}
