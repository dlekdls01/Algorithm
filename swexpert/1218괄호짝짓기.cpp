#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define TESTCASE 10

bool solution(string str, int n) {
	stack<char> st;

	for (int i = 0; i < n; i++) {
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
		case '<':
			st.push(str[i]);
			break;
		case ')':
			if (st.empty()) return false;
			if (st.top() != '(') return false;
			st.pop();
			break;
		case ']':
			if (st.empty()) return false;
			if (st.top() != '[') return false;
			st.pop();
			break;
		case '}':
			if (st.empty()) return false;
			if (st.top() != '{') return false;
			st.pop();
			break;
		case '>':
			if (st.empty()) return false;
			if (st.top() != '<') return false;
			st.pop();
			break;
		default:
			break;
		}
	}
	return true;
}
int main() {
	int n;
	string str;
	for (int t = 1; t <= TESTCASE; t++) {
		cin >> n;
		cin >> str;
		if (solution(str, n))
			cout << "#" << t << " " << "1\n";
		else
			cout << "#" << t << " " << "0\n";
	}
	return 0;
}
