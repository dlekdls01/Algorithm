#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;


int n, m;
int map[55][15];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int dist[110][15]; // home - ch 의 거리
int anw = 987654321;

int check(vector<int> v) {
	int sum = 0;
	int minx = 0;
	for (int i = 0; i < home.size(); i++) {
		minx = 987654321;
		for (int j = 0; j < v.size(); j++) {
			minx = min(minx, dist[i][v[j]]);
		}
		sum += minx;
	}
	return sum;
}
void f(int idx, int cnt, vector<int> v) {
	if (cnt == m) {
		int x = check(v); 
		if (anw > x)
			anw = x;
		return;
	}
	if (idx >= chicken.size()) return;

	//o
	v.push_back(idx);
	f(idx + 1, cnt + 1, v);
	v.pop_back();
	//x
	f(idx + 1, cnt, v);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if(map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	/////////
	
	//dist 구하기
	int d;
	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			d = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
			dist[i][j] = d;
		}
	}

	vector<int> v;
	f(0, 0, v);
	cout << anw;
	return 0;
}
