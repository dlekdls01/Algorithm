#include<iostream>
#include<queue>
#include<string>
using namespace std;

int L(int num) {
	int x = num * 10;
	num = x % 10000;
	num += x / 10000;
	return num;
}
int R(int num) {
	int x = num / 10;
	num =( num % 10)*1000;
	num += x;
	return num;
}
int main() {
	int x, tx;
	int visit[10000];;
	string str;
	int T;
	int a, b;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> a >> b;

		queue<pair<int, string>> q;  // num, dslr
		q.push(make_pair(a, ""));
		std:fill_n(visit, 10000, 0);
		visit[a] = -1;

		while (!q.empty())
		{
			x = q.front().first;
			str = q.front().second;
			q.pop();
      
			if (x == b) {
				break;
			}
			tx = 2 * x;
			if (tx > 9999) tx = tx % 10000;
			if (visit[tx] != -1) {
				visit[tx] = -1;
				q.push(make_pair(tx, str + "D"));
			}

			tx = x - 1;
			if (tx == -1) tx = 9999;
			if (visit[tx] != -1) {
				visit[tx] = -1;
				q.push(make_pair(tx, str + "S"));
			}

			tx = L(x);
			if (visit[tx] != -1) {
				visit[tx] = -1;
				q.push(make_pair(tx, str + "L"));
			}

			tx = R(x);
			if (visit[tx] != -1) {
				visit[tx] = -1;
				q.push(make_pair(tx, str + "R"));
			}
		}

		cout << str << endl;
	}
	return 0;
}
