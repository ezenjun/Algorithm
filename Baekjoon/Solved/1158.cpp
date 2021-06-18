#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> person;
	for (int i = 1; i <= n; i++) {
		person.push(i);
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < k - 1; j++) {
			person.push(person.front());
			person.pop();
		}
		cout << person.front() << ",";
		person.pop();
	}
	cout << person.front() << ">" << endl;
	return 0;
}