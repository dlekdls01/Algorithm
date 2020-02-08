#include <iostream>
#include <vector>
#include<math.h>
#include<queue>
#include <functional>
using namespace std;

int n;
vector<vector<int>> v;
vector<int> edge;
vector<int> time;
vector<int> val;
int main(void) {
	int x = 0;
	int idx = 1;

	cin >> n;
	edge.resize(n + 1);
	time.resize(n + 1);
	v.resize(n + 1);
	val.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> x;
		time[i] = x;
		cin >> x;
		while (x != -1)
		{
			v[x].push_back(i);
			edge[i] ++;
			cin >> x;
		}
	}

	//
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (edge[i] == 0) {
			q.push(i);
			val[i] = time[i];
		}
	}

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for (auto y : v[x]) {
			edge[y] --;
			val[y] = max(val[y], val[x] + time[y]);
			if (edge[y] == 0) {
				edge[y] --;
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << val[i] << endl;
	}
	return 0;
}
