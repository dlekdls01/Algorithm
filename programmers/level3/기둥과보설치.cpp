#include<iostream>
#include<vector>
using namespace std;

int map[101][101][2];
int n;
//x가로 y세로
bool checkMake(int x, int y, int a) {
	//기둥
	if (a == 0) {
		if (y == 0)return true;
		if (map[y-1][x][0]) return true;
		if (map[y][x][1] || (x > 0 && map[y][x - 1][1])) return true;
	}
	//보
	else if (a == 1) {
		if (x == n - 1 || y==0) return false;
		if (map[y-1][x][0] || map[y-1][x+1][0]) return true;
		if (x > 0 && map[y][x - 1][1] && map[y][x + 1][1]) return true; 
	}
	return false;
}

bool checkDelete(int x, int y, int a) {
	//기둥
	if (a == 0) {
		if (map[y+1][x][0] && !checkMake(x, y + 1, 0)) return false;
		if (map[y+1][x][1] && !checkMake(x, y + 1, 1))return false; 
		if (x>0 && map[y+1][x-1][1] && !checkMake(x - 1, y+1, 1)) return false; 
	}
	//보
	else if (a == 1) {
		if (map[y][x][0] && !checkMake(x, y, 0)) return false; 
		if (map[y][x+1][0] && !checkMake(x + 1, y, 0)) return false;
		if (map[y][x+1][1] && !checkMake(x + 1, y, 1)) return false; 
		if (x > 0 && map[y][x-1][1] && !checkMake(x - 1, y, 1)) return false; 
	}
	return true;
}
void pr() {
	cout << "-----------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j][0] << "/" << map[i][j][1] << "  ";
		}cout << endl;
	}
}
vector<vector<int>> solution(int N, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	n = N+1;

	for (int i = 0; i < build_frame.size(); i++) {
		//cout << build_frame[i][0] << " " << build_frame[i][1] << " " << build_frame[i][2] << " " << build_frame[i][3] << endl;
		
		//삭제
		if (build_frame[i][3] == 0) {
			map[build_frame[i][1]][build_frame[i][0]][build_frame[i][2]] = 0;
			if (!checkDelete(build_frame[i][0],build_frame[i][1],build_frame[i][2])) {
				map[build_frame[i][1]][build_frame[i][0]][build_frame[i][2]] = 1;
			}
		}
		//설치
		else if (build_frame[i][3] == 1) {
			if (checkMake(build_frame[i][0], build_frame[i][1], build_frame[i][2])) {
				map[build_frame[i][1]][build_frame[i][0]][build_frame[i][2]] = 1;
			}
		}
		//pr();
	}

	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i][0]) answer.push_back({ i,j,0 });
			if (map[j][i][1]) answer.push_back({ i,j,1 });
		}
	}
	return answer;
}
