#include<iostream>
using namespace std;

int k, n;
long long arr[10001];

long long getLineNum(long long len) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / len;
	}
	return cnt;
}

int main() {
	long long maxN = 0;
	long long minN = 1;

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (maxN < arr[i]) maxN = arr[i];
	}

	long long  mid;
	long long cnt;
	long long anw = 1;

	while (minN <= maxN) {
		mid = (minN + maxN) / 2;
		cnt = getLineNum(mid);
		if (cnt >= n) {
			if (anw < mid) anw = mid;
			minN = mid + 1;
		}
		else maxN = mid - 1;
	}
	cout << anw;
	return 0;
}
