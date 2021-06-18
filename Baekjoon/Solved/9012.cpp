#include <iostream>
#include <string>
using namespace std;

string check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
		}
		if (cnt < 0) {
			return "NO";
		}
	}
	if (cnt == 0) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	int n = 0;
	string s;
	cin >> n;
	while (n--) {
		cin>>s;
		cout << check(s) << endl;
	}
}