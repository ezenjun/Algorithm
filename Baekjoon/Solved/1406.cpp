#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
string s;

int main() {
	cin.tie(NULL);
	int n;
	char add, run;
	cin >> s;
	stack<char> left, right;
	for (int i = 0; i < s.length(); i++) {
		left.push(s[i]);
	}

	cin >> n;
	while(n--) {
		cin >> run;
		if (run == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			
		}
		else if (run == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			
		}
		else if (run == 'B') {
			if (!left.empty()){
				left.pop();
			}
		}
		else if (run == 'P') {
			cin >> add;
			left.push(add);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}