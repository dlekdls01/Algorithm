#include <iostream>
#include <vector>
#include<math.h>
#include<queue>
#include <functional>
using namespace std;

#define INF 987654321
#define MAX 1001

struct Edge {
	int vertex;
	int cost;
};
struct cmp {
	bool operator()(Edge a, Edge b) {
		if (a.cost > b.cost) return true;
		else if (a.cost == b.cost) return a.vertex > b.vertex;
		else return false;
	}
};
int n, m;
int start, dest;
vector<Edge> graph[MAX];
int dist[MAX];
void solution() {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	Edge now;
	fill_n(&dist[0], n + 1, INF);
	dist[start] = 0;
	now = { start, 0 };
	pq.push(now);

	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();

		for (auto next : graph[now.vertex]) {
			if (dist[next.vertex] > dist[now.vertex] + next.cost) {
				dist[next.vertex] = dist[now.vertex] + next.cost;
				next = { next.vertex, dist[next.vertex] };
				pq.push(next);
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int from, to, val;
	Edge edge;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> val;
		edge = { to, val };
		graph[from].push_back(edge);
	}
	cin >> start >> dest;
	solution();
	cout << dist[dest];
	return 0;
}
