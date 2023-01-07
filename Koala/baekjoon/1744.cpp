#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, one, zero;
vector<int> pos;
vector<int> neg;

int main()
{
	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 1) pos.push_back(tmp);
		else if (tmp < 0) neg.push_back(-tmp);
		else if (tmp == 0) zero++;
		else one++;
	}
	if (pos.size() % 2 == 1)
		pos.push_back(1);
	if (neg.size() % 2 == 1) {
		if (zero == 0) neg.push_back(-1);
		else neg.push_back(0);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	int sum = one;
	for (int i = 0; i < pos.size(); i += 2) 
		sum += pos[i] * pos[i + 1];
	for (int i = 0; i < neg.size(); i += 2)
		sum += neg[i] * neg[i + 1];
	cout << sum;
	
}