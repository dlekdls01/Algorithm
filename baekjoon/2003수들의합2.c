#include<stdio.h>
int main() {
	int n, m;
	int arr[10001];

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int sum = 0;
	int idx = 0;
	int anw = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		printf("%d %d %d %d\n", i, idx, sum,anw);
		while (sum > m) {
			sum -= arr[idx];
			idx++;
		}
		if (sum ==m){
			anw++;
		}
	}
	printf("%d", anw);
}
