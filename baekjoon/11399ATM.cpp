#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	int anw = 0;
	int curT = 0;
	for (int i = 0; i < n; i++) {
		anw += (curT + v[i]);
		curT += v[i];
	}
	cout << anw;
	return 0;
}
