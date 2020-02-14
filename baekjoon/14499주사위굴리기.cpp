#include<iostream>
using namespace std;

struct ST
{
	int u, d, r, l, f, b;	//위,아래,우,좌,앞,뒤
	int x, y;
};
int n, m, k, S;
ST st;
int map[21][21];

void change(int val) {
	int temp;
	temp = st.u;
	switch (val)
	{
	case 1:
		st.u = st.l;
		st.l = st.d;
		st.d = st.r;
		st.r = temp;
		break;
	case 2:
		st.u = st.r;
		st.r = st.d;
		st.d = st.l;
		st.l = temp;
		break;
	case 3:
		st.u = st.b;
		st.b = st.d;
		st.d = st.f;
		st.f = temp;
		break;
	case 4:
		st.u = st.f;
		st.f = st.d;
		st.d = st.b;
		st.b = temp;
		break;
	}
}
int main() {
	st = { 0,0,0,0,0,0,0,0 };
	cin >> n >> m >> st.x >> st.y >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int s = 0; s < k; s++) {
		cin >> S;
		switch (S)
		{
		case 1:
			if (st.y > m - 2) continue;
			st.y = st.y + 1;

			if (map[st.x][st.y] == 0)
				map[st.x][st.y] = st.r;
			else{
				st.r = map[st.x][st.y];
		        map[st.x][st.y] = 0;
            }
			break;
		case 2:
			if (st.y < 1) continue;
			st.y = st.y - 1;

			if (map[st.x][st.y] == 0)
				map[st.x][st.y] = st.l;
			else{
				st.l = map[st.x][st.y];
		        map[st.x][st.y] = 0;
            }
			break;
		case 3:
			if (st.x < 1) continue;
			st.x = st.x - 1;

			if (map[st.x][st.y] == 0)
				map[st.x][st.y] = st.f;
			else{
				st.f = map[st.x][st.y];
		        map[st.x][st.y] = 0;
            }
			break;
		case 4:
			if (st.x > n - 2)continue;
			st.x = st.x + 1;

			if (map[st.x][st.y] == 0) 
				map[st.x][st.y] = st.b;
			else{
				st.b = map[st.x][st.y];
		        map[st.x][st.y] = 0;
            }
			break;
		}
		change(S);
		cout << st.u <<endl;
	}
	return 0;
}
