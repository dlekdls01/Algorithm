#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int arr[100001];

void quickSort(int arr[], int size) { 
	int pivot = arr[0]; 
	int cursor = 0; 
	for (int i = 1; i < size; i++) { 
		if (pivot > arr[i]) { 
			cursor++; 
			swap(arr[cursor], arr[i]);
		} 
	} 
	int temp = arr[0];
	arr[0] = arr[cursor];
	arr[cursor] = temp;
	if (cursor > 0) { 
		quickSort(arr, cursor);
	} 
	if (cursor + 1 < size - 1) { 
		quickSort(arr + cursor + 1, size - cursor - 1);
	} 
}

void bsearch(int n, int key) {
	int start = 0;
	int end = n - 1;
	int mid;

	while (end-start >=0)
	{
		mid = (start + end) / 2;

		if (arr[mid] == key) {
			printf("1\n");
			return;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	printf("0\n");
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr, n);
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
		bsearch(n, v2[i]);
	}

	return 0;
}
