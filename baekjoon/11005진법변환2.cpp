#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	long long int n, b;
	string num[36];
	vector<string> v;
	cin >> n >> b;

	for (int i = 0; i < 10; i++) {
		num[i] = to_string(i);
	}
	for (int i = 10; i < 36; i++) {
		num[i] = 'A' + i-10;
	}


	while (n>= b)
	{
		v.push_back(num[n%b]);
		n /= b;
	}

	v.push_back(num[n%b]);
	for (int i = v.size()-1; i >=0; i--)
		cout << v[i];
	return 0;
}
