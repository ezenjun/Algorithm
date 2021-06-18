#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[1001] = { 0 }, d[1001] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) { // i��° ���� d 
			if (arr[j] < arr[i] && d[j] + 1 > d[i]) { // ���� �ڽ��� ������
				d[i] = d[j] + 1;
			}
			count = max(count, d[i]);
		}
	}
	cout << count << endl;
}