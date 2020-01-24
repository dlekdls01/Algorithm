#include<iostream>
#include<deque>
#include<set>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int n, k, s;
char arr[29];
deque<char> dq;
set <long long int> nums;

//10 A , 11 B , 12 C, 13 D , 14 E, 15 F
//	1F7 -> 1*16^2 + 15*16^1 +  7*16^0 = 256 + 240 + 7 = 503
//  1B3 -> 1*16^2 + 11*16^1 + 3 =  256 + 176 1
int toTen(string s) {
	int len = s.size();
	int num = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num += (s[i] - '0')*pow(16, len - i -1);
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			num += (s[i] - 'A' + 10)*pow(16, len -i -1);
		}
	}
	return num;
}
void f() {
	string str = "";
	char x;
	long long int g;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < n; j++) {
			if (j % s == 0) {
				if (j != 0) {
					g = toTen(str);
					nums.insert(g);
					//cout << str << " " << g << endl;
				}
				str = "";
			}
			str += dq[j];
		}
		g = toTen(str);
		nums.insert(g);
		////

		x = dq.back();
		dq.pop_back();
		dq.push_front(x);
		
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		dq.clear(); nums.clear();
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			dq.push_back(arr[i]);
		}
		s = n / 4;
		f();

		int idx=0;
		for (set<long long int>::iterator i=nums.begin(); i != nums.end(); i++) {
			idx++;
			
			if (idx == nums.size() + 1 - k) {
				cout << "#"<<t<<" "<<*i << endl;
				break;
			}
		}
	}
	return 0;
}
