#include<iostream>
#include<vector>
using namespace std;

int n, m, c;
int map[11][11];
int getM[11][11];	//채취값
vector<int>v;

int getMax() {
	int sum = 0;
	int sum2 = 0;
	int maxn = 0;

	for (int s = 0; s < (1 << m); s++) {
		sum = sum2 = 0;
		for (int i = 0; i < m; i++) {
			if ((s&(1 << i)) != 0) {
				sum += v[i];
				sum2 += v[i] * v[i];
			}
			if (sum > c)
				break;
		}
		if (sum <= c && maxn < sum2)
			maxn = sum2;
	}
	return maxn;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		/// [i][j]~[i][j+m] 까지 m개택했을때 최댓값구해서 getM배열에 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m ; j++) {
				v.clear();
				for (int k = 0; k < m; k++) {
					v.push_back(map[i][j + k]);
				}
				getM[i][j] = getMax();
			}
		}

		/// 2개 택해서 최댓값 구하기
		int sum=0, anw=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n-m; j++) {
				//같은 가로줄에있는경우
				for (int k = j+n; k <= n - m; k++) {
					sum = getM[i][j] + getM[i][k];
					if (anw < sum) anw = sum;
				}

				//다른 가로줄에있는경우
				for (int k = i + 1; k < n; k++) {
					for (int a = 0; a <= n - m; a++) {
						sum = getM[i][j] + getM[k][a];
						if (anw < sum) anw = sum;
					}
				}
			}
		}
		cout <<"#"<<t<<" "<< anw << endl;
	}
	return 0;
}
