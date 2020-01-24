#include<iostream>
using namespace std;

int n, k;
int coins[10];



int main() {
	int anw = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k >= coins[i]) {
			anw += k / coins[i];
			k = k % coins[i];
			if (k == 0)
				break;
		}
	}
	cout << anw;
	return 0;
}
