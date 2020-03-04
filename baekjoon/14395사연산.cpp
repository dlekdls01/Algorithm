#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;

//int visit[1000000001];
map<string, int> visit;
struct ST
{
	long long int n;
	vector<char>v;
};
int main() {
	long long int x, y;
	cin >> x >> y;

	if (x == y) {
		cout << "0" << endl;
		return 0;
	}
	if (y == 1) {
		cout << "/" << endl;
		return 0;
	}
	if (y == 0) {
		cout << "-" << endl;
		return 0;
	}

	ST now, next;
	vector<char> v;
	visit[std::to_string(x)] = -1;
	now = { x,v };
	queue<ST> q;
	q.push(now);

	while (!q.empty())
	{
		now = q.front();
		v = now.v;
		q.pop();
		//cout << now.n << endl;
		if (now.n == y) {
			for (int i = 0; i < now.v.size(); i++) {
				cout << now.v[i];
			}
			return 0;
		}

		//*
		x = now.n * now.n;
		if (x<=y && visit.count(std::to_string(x)) == 0) {
			visit[std::to_string(x)] = -1;
			v.push_back('*');
			next = { x,v };
			q.push(next);
			v.pop_back();
		}
		//+
		x = now.n + now.n;
		if (x<=y && visit.count(std::to_string(x)) == 0) {
			visit[std::to_string(x)] = -1;
			v.push_back('+');
			next = { x,v };
			q.push(next);
			v.pop_back();
		}
		//%
		x = now.n / now.n;
		if (visit.count(std::to_string(x)) == 0) {
			visit[std::to_string(x)] = -1;
			v.push_back('/');
			next = { x,v };
			q.push(next);
			v.pop_back();
		}
	}
	cout << "-1";
	return 0;
}
