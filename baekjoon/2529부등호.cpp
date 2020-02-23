#include<iostream>
#include<queue>
using namespace std;


int k;
char arr[10];
int num[2][10] = { { 0,1,2,3,4,5,6,7,8,9 },{9,8,7,6,5,4,3,2,1,0} };
bool flag = false;

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
bool poss(int val) {
	int a, b;
	for (int i = 0; i < k; i++) {
		a = num[val][i];
		b = num[val][i + 1];

		if (arr[i] == '>') {
			if (a < b) {
				return false;
			}
		}
		else if (arr[i] == '<') {
			if (a > b) {
				return false;
			}
		}
	}


	for (int i = 0; i <= k; i++)
		cout << num[val][i];
	cout << endl;

	return true;
}
void f(int n, int r, int val) {
	if (r == 0) {
		flag = poss(val);
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(&num[val][i], &num[val][n - 1]);
		f(n - 1, r - 1, val);
		swap(&num[val][i], &num[val][n - 1]);
		if (flag)
			return;
	}
}
int main() {

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	f(k+1, k+1, 1);
	f(k+1, k+1, 0);
	return 0;
}
