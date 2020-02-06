#include <iostream>
#include <vector>
#include<math.h>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> v;
int visit[32002];
vector<int> output;
void fuc(int x) {
	int y;

	for (int i = 0; i < v[x].size(); i++) {
		y = v[x][i];
		if (visit[y] == -1) continue;
		visit[y] = -1;
		fuc(y);
	}
	output.push_back(x);
}
int main(void) {
	int x, y;
	cin >> n >> m;
	v.resize(n+1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
	}

	//
	for (int i = 1; i <= n; i++) {
		if (visit[i] != -1) {
			visit[i] = -1;
			fuc(i);
		}
	}
	for (int i = output.size() - 1; i >= 0; i--)
		cout << output[i] << " ";
	return 0;
}
