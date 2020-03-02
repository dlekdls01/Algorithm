#include<iostream>
#include<vector>
using namespace std;


int map[9][9];
vector<pair<int, int>> v;		//빈칸 인덱스저장하는 벡터
bool flag = false;				//정답 찾으면 끝내는 플래그

bool check(int x, int y, int num) {
	int a, b;
	a = (x / 3) * 3;
	b = (y / 3) * 3;

	for (int i = a; i < a + 3; i++) {			//3*3 정사각형 확인
		for (int j = b; j < b + 3; j++) {
			if (map[i][j] == num)
				return false;
		}
	}
	for (int i = 0; i < 9; i++) {				//가로세로 확인
		if (map[i][y] == num)
			return false;
		if (map[x][i] == num)
			return false;
	}
	return true;
}
void f(int idx) {
	int x, y;

	if (idx == v.size()) {			//빈칸모두 채웠으면 성공
		flag = true;
		return;
	}

	x = v[idx].first;
	y = v[idx].second;

	for (int i = 1; i <= 9; i++) {	//1~9까지 다넣어봄
		if (check(x, y, i)) {		//넣을수있는지 확인
			map[x][y] = i;
			f(idx + 1);
			 
			if (flag)
				return;
			map[x][y] = 0;

		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	f(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j]<<" ";
		}cout << endl;
	}
	return 0;
}
