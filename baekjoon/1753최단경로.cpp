#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define INF 987654321


int v, e, k;
vector<pair<int,int>> graph[20001]; //from>{to, cost}
int dist[20001];
void solution() {
	int now, nowCost, next, nextCost;
	fill_n(&dist[0], v + 1, INF);		
	priority_queue<pair<int, int>> pq;

	dist[k] = 0;			
	pq.push(make_pair(0, k));	

	while (!pq.empty())
	{
		nowCost = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		//if (dist[now] < nowCost) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			next = graph[now][i].first;
			nextCost = graph[now][i].second;

			if (dist[next] >nextCost + dist[now]) {
				dist[next] = nextCost + dist[now];
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int from, to, cost;

	cin >> v >> e;
	cin >> k;

	for (int i = 0; i < e; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}
	solution();
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i]<<endl;
	}
	return 0;
}
