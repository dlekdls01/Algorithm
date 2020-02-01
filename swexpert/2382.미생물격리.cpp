
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ST
{
	int x, y;
	int cnt;
	int dir;
}typedef ST;

int main() {
	int T;
	int n, M, k;
	int x, y, c, d;
	pair<int,int> map[101][101];	//이동한위치에온 군집의 최대미생물수와 군집의인덱스저장
	vector<ST>v;
	ST st;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		cin >> n >> M >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y >> c >> d;
			st = { x,y,c,d };
			v.push_back(st);
		}
		
		//시간
		for (int m = 0; m < M; m++) {		
			fill_n(&map[0][0], 101 * 101, make_pair(0, -1));

			//미생물수
			for (int i = 0; i < v.size(); i++) {	
				if (v[i].cnt == 0) continue;

				x = v[i].x;				//x	
				y = v[i].y;				//y
				c = v[i].cnt;			//cnt
				d = v[i].dir;			//dir	1:상 2:하 3:좌 4:우 -> -1

				x = x + dx[d - 1];
				y = y + dy[d - 1];

				//빨강셀일경우
				if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
					if (d % 2 == 0) d--;
					else d++;
					c = c / 2;
				}
				v[i] = { x,y,c,d };


				if (map[x][y].first < c) {			//이전에있는 군집의미생물수보다 더크다면
					if (map[x][y].second != -1) {	
						v[i].cnt += v[map[x][y].second].cnt;	//이전에있는 군집의미생물수를 더해줌
						v[map[x][y].second].cnt = 0;			//이전에있는 군집의미생물수를 0으로해줌
					}
					map[x][y].first = c;			//cnt저장
					map[x][y].second = i;			//최대cnt의 미생물인덱스저장
				}
				else {
					v[map[x][y].second].cnt += v[i].cnt;
					v[i].cnt = 0;
				}
			}
			
			
		}///시간
		
		int anw = 0;
		for (int i = 0; i < v.size(); i++) {
			anw += v[i].cnt;
		}
		cout << "#" << t << " " << anw << endl;

	}


	return 0;
}
