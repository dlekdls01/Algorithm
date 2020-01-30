#include<iostream>
using namespace std;


int d, w, k;
int map[14][21];
int anw = 100;
bool check() {
	bool check = false;
	bool flag = false;
	int cnt = 0;

	for (int j = 0; j < w; j++) {
		flag = false;
		check = false;
		cnt = 0;
		for (int i = 0; i < d; i++) {
			if (map[i][j] == 1 && !flag) {		//전에0이엇고 현재1인경우
				flag = true;
				cnt = 1;
			}
			else if (map[i][j] == 1 && flag) {	//전에1이었고 현재1인경우
				cnt++;
			}
			else if (map[i][j] == 0 && flag) {		//전에1이었고 현재0인경우
				flag = false;
				cnt = 1;
			}
			else if (map[i][j] == 0 && !flag) {		//전에0이었고 현재0인경우
				cnt++;
			}
			if (cnt == k) {
				check = true;
				break;
			}
			if (d - i - 1 + cnt < k) 
				return false;
		}
		if (!check)
			return false;
	}
	return true;
}
void copyArr(int a[14][21], int b[14][21]) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void changeArr(int idx, int val) {
	for (int i = 0; i < w; i++) {
		map[idx][i] = val;
	}
}
void resetArr(int idx, int a[14][21], int b[14][21]) {
	for (int i = 0; i < w; i++) {
		a[idx][i] = b[idx][i];
	}
}
void f(int idx, int cnt) {	//세로 인덱스, 약물횟수
	int temp[14][21];
	//copyArr(temp, map);


	if (anw <= cnt)
		return;
	if (check()) {
		if (anw > cnt)
			anw = cnt;
		return;
	}
	if (idx >= d) {
		return;
	}
	for (int i = idx + 1; i < d; i++) {
		//약물x
		f(i, cnt);

		//약물A
		resetArr(i, temp, map);
		changeArr(i, 1);
		f(i, cnt + 1);
		changeArr(i, 0);
		f(i, cnt + 1);
		resetArr(i, map, temp);
		if (anw != 100)
			return;
	}
}
int main() {
	int T;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		anw = 100;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		//////////////
		if (k == 1) {
			cout << "#" << t << " " << "0" << endl;
			continue;
		}
		else {
			f(-1, 0);
			cout << "#" << t << " " << anw << endl;
		}
	}
	return 0;
}
