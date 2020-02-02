#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;
int n, dsize;
int anw = INT16_MAX;
int visit[10];
vector<int> weak;
vector<int> dist;


int check(vector<int> d, int start) {
    //순서대로 q에 넣어줌
	queue<int> q;
	for (int i = start; i < weak.size(); i++) {
		q.push(weak[i]);
	}
	for (int i = 0; i < start; i++) {
		q.push(weak[i]+n);
	}

	//q에 dist값해서 측정
	int cur = q.front() + d[0]; q.pop();
	int idx = 1;
	while (!q.empty())
	{
        if (anw < idx) return INT16_MAX; //이미구한답보다큰경우가지치기
		if (cur < q.front()) {
			if (idx == d.size()) return INT16_MAX;
			cur = q.front() + d[idx];
			idx++;
		}
		q.pop();
	}
	return idx;
}
//dist모든조합탐색함수
void dfs(int cnt, vector<int> d) {

	if (cnt == dist.size()) {
		int num;
        //1,5,6,10//5,6,10,13//6,10,13,17 이런식으로 시작지점을 모두탐색
		for (int i = 0; i < weak.size(); i++) {
			num = check(d, i);
			if (anw > num) anw = num;
		}
		return;
	}
	for (int i = 0; i < dist.size(); i++) {
		if (visit[i]) continue;

		visit[i] = 1;
		d.push_back(dist[i]);
		dfs(cnt + 1, d);
		visit[i] = 0;
		d.pop_back();
	}

	return;
}
int solution(int N, vector<int> _weak, vector<int> _dist) {
	n = N;
	weak = _weak;
	dist = _dist;

	vector<int>d;
	dfs(0, d);
	if (anw == INT16_MAX) anw = -1;
	return anw;
}
