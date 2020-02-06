#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define NODE_MAX 801
#define INF 987654321
#define ll long long

struct Edge {
	int vertex;
	ll cost;
};
struct cmp{
	bool operator()(Edge a, Edge b) {
		if (a.cost > b.cost) return true;
		else if (a.cost == b.cost)return a.vertex > b.vertex;
		return false;
	}
};

int n, e;
int x, y;
vector<Edge> graph[NODE_MAX];
ll dist[3][NODE_MAX]; //출발지에서 i노드까지의 최단거리저장

void solution(int start, int i) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	Edge now;
	dist[i][start] = 0;
	now = { start, 0 };
	pq.push(now);

	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();

		for (auto next : graph[now.vertex]) {
			if (dist[i][next.vertex] > dist[i][now.vertex] + next.cost) {
				dist[i][next.vertex] = dist[i][now.vertex] + next.cost;
				pq.push({ next.vertex, dist[i][next.vertex] });
			}
		}
	}
}
int main() {
	int from, to, cost;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}
	cin >> x >> y;

	fill_n(&dist[0][0], 3 * NODE_MAX, INF);
	ll anw = 0;
	int start[3] = { 1, x, n };
	for (int i = 0; i < 3; i++) {
		solution(start[i], i);
	}
	anw = min(dist[0][x] + dist[1][y] + dist[2][y], dist[0][y] + dist[1][y] + dist[2][x]);
	if (anw >= INF) anw = -1;
	cout << anw;
	return 0;
}
