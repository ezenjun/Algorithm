#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

float M1, p;
int N, M, s, d, dp[10002];

int main(void) {
	while (1) {
		memset(dp, 0, sizeof(dp));
		cin >> N >> M1;
		if (N == 0 && M1==0)
			break;
		M = M1 * 100;
		for (int i = 0; i < N; i++) {
			cin >> s >> p;
			d = p * 100;
			for (int t = d; t <= M; t++)
				dp[t] = max(dp[t], dp[t - d] + s);
		}
		cout << dp[M] << endl;
	}
	return 0;
}