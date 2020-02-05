#include<iostream>
#include<algorithm> 
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdlib>  //abs()
using namespace std;


int money[4] = { 0 };
int month[12] = { 0 };
vector<int> v;
void solv(int num, int cnt) {
	if (cnt >= 12) {
		v.push_back(num);
		return;
	}
	if (month[cnt] > 0) {
		
		solv(num + money[0] * month[cnt],cnt+1);
		solv(num +  money[1],cnt+1);
		solv(num +  money[2], cnt + 3);
	}
	else
	{
		solv(num, cnt + 1);
	}
	
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++)
			cin >> money[i];
		for (int i = 0; i < 12; i++)
			cin >> month[i];
		solv(0,0);
		v.push_back(money[3]);
		
		int minnum = *min_element(v.begin(), v.end());
		cout << "#" << t << " " << minnum << endl;
		v.clear();
	}
	
	return 0;
}


