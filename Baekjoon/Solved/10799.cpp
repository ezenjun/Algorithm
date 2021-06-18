#include <iostream>
#include <stack>
using namespace std;

int laser(string a) {
	int cutbar = 0;
	int n = a.size();
	stack<int> s;

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() +1 == i) {
				s.pop();
				cutbar += s.size();
			}
			else {
				s.pop();
				cutbar += 1;
			}
		}
	}
	return cutbar;
}

int main() {
	string sen;
	cin >> sen;
	cout << laser(sen) << endl;
}