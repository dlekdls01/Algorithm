#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[21][21];
int anw = 100000;							//팀 차이값의 최소
int visit[21];								//숫자 사용했는가
vector<vector<int>>v(2);					//v[0]팀  v[1]팀

int getNum() {								//arr[i][j]합구한후 차이값 리턴
	int a = 0, b = 0;
	for (int i = 0; i < v[0].size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			a += arr[v[0][i]][v[0][j]];
		}
	}
	for (int i = 0; i < v[1].size(); i++) {
		for (int j = 0; j < v[1].size(); j++) {
			b += arr[v[1][i]][v[1][j]];
		}
	}
	return abs(a - b);
}

int main() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int s = 0; s<(1<< n); s++) {
		v[0].clear();
		v[1].clear();
		for (int i = 0; i < n; i++) {
			if ((s&(1 << i)) == 0)
				v[0].push_back(i);
			else
				v[1].push_back(i);
		}
		x = getNum();
		if (anw > x)
			anw = x;

	}
	cout << anw;
	return 0;
}
