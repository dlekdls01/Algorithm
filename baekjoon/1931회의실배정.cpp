#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());

	int anw = 1, curTime=v[0].first;

	for (int i = 1; i < n; i++) {
		if (curTime <= v[i].second) {
			curTime = v[i].first;
			anw++;
		}
	}
	cout << anw;
	return 0;
}
