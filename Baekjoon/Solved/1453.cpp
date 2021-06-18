#include <iostream>
using namespace std;

int main() {
	int n, seat[101] = {0,}, sit, reject=0;
	cin >> n;
	while (n--) {
		cin >> sit;
		if (seat[sit] != 0) {
			reject++;
		}
		else {
			seat[sit] = 1;
		}
	}
	cout << reject << endl;
}