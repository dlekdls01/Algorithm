#include<iostream>
#include<algorithm>
using namespace std;

# define ll long long

int main() {
	ll n, m;
	ll arr[1000001];
	ll minN=0, midN, maxN = 0, sum=0, anw=0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxN = max(maxN, arr[i]);
	}

	while (minN <= maxN)
	{
		sum = 0;
		midN = (minN + maxN) / 2;
        //잘린길이 총 합
		for (int i = 0; i < n; i++) {
            if(arr[i] > midN)
			    sum += (arr[i] - midN);
        }

		if (sum >= m) {
			anw = max(anw, midN);
			minN = midN + 1;
		}
		else
			maxN = midN - 1;
	}
	cout << anw;
	return 0;
}
