#include <iostream>
#include <algorithm>
#include<cstring>
#include <vector>

using namespace std;

int dp[31][31];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
	int n, m;

	for (int i = 1; i < 31; i++) {
		dp[1][i] = i;
	}

	for (int r = 2; r < 31; r++) {
		for (int c = 2; c < 31; c++) {
			for (int k = c - 1; k > 0; k--) {
				dp[r][c] += dp[r - 1][k];
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
	    cout<< dp[n][m]<< "\n";
	}

	return 0;
}