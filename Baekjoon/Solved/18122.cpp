#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 1;
	for (int i = 0; i < N + 2; i++) {
		count *= 2;
		count %= 1000000007;
	}
	count -= 5;
	cout << count;
}