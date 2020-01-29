#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>>v;
void hanoi(int a, int b, int c, int n) {
	if (n == 1) {
		v.push_back({ a,c });
	}
	else {
		hanoi(a, c, b, n - 1);
		v.push_back({ a,c });
		hanoi(b, a, c, n - 1);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	hanoi(1, 2, 3, n);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second <<"\n";
	}
	return 0;
}
