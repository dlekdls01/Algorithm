#include<iostream>
using namespace std;

int n;
int inOrder[100001];
int postOrder[100001];
int idx[100001];
void fuc(int istart, int iend, int pstart, int pend) {
	
	int mid = idx[postOrder[pend]]; //root값 = post의마지막값	
	cout << inOrder[mid] << " "; 

	if (istart < mid)
		fuc(istart, mid - 1, pstart, pstart+mid-istart-1);
	if (mid < iend)
		fuc(mid + 1, iend, pstart + mid - istart, pend - 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inOrder[i];
		idx[inOrder[i]] = i;
	}
	for (int i = 0; i < n; i++) 
		cin >> postOrder[i];

	//
	fuc(0, n - 1, 0, n - 1);
	return 0;
}
