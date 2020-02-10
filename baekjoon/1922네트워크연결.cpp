#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
using namespace std;

#define P pair<int,int>

int visit[10010];
vector<P> edge[10010];

int prim() {
	int anw = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, 1));
	P now, next;

	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();

		if (visit[now.second]) continue;

		visit[now.second] = 1;
		anw += now.first;

		for (auto x : edge[now.second]) {
			if (visit[x.second])continue;
			pq.push(x);
		}
	}
	return anw;
}
int main() {
	int n, m;
	int x, y, w;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		edge[x].push_back(P(w, y));
		edge[y].push_back(P(w, x));
	}

	cout << prim();
	return 0;
}
