#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int n, m;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		v.push_back(make_pair(i,m));
	}
	while (v.empty() != true) {
		cout << v.front().first<<" ";
		int move = v.front().second;
		v.erase(v.begin());

		if (move < 0) { 
			for (int j = 0; j < abs(move); j++) {
				v.insert(v.begin(), v.back());
				v.erase(v.end());
			}
		}
		else { 
			for (int j = 0; j < move - 1; j++) {
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}
	return 0;
}