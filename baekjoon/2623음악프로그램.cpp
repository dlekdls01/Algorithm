#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main() {
	int n, m,x,y,k;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int>edge(n + 1, 0);
	vector<int> anw;

	for (int i = 0; i < m; i++) {
		cin >> k;
		cin >> x;
		for (int j = 1; j < k; j++) {
			cin >> y;
			graph[x].push_back(y);
			edge[y]++;
			x = y;
		}
	}

	//
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (edge[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		anw.push_back(x);

		for (auto next : graph[x]) {
			edge[next]--;
			if (edge[next] == 0)
				q.push(next);
		}
	}
	if (anw.size() < n) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < anw.size(); i++) {
		cout << anw[i] << " ";
	}
	return 0;
}
