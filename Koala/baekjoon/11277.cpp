#include <iostream>
#include <vector>
using namespace std;
bool ch[21];
vector <pair<int, int>> e;
int n, m;
bool res; 
bool go() {
    bool t;
    for (int i = 0; i < e.size();i++) {
        int c = e[i].first, d = e[i].second; // 식의 한 절 
		bool a, b; // 그 변수들의 비트 값
		if (c < 0) a = ch[-c] == 0 ? 1 : 0; // 음수라면 해당 비트 값의 반대값
		else a = ch[c];
		if (d < 0) b = ch[-d] == 0 ? 1 : 0;
		else b = ch[d];
		if (!i) t = (a | b); // 비트 연산
		else t = (t & (a | b));
		if (!t) return false;
	}
	return true;
}
bool solve(int s) { // 모든 경우
    if (n + 1 == s) {
       if (go()) return true;
       return false;
    }
	ch[s] = 1;
	if (solve(s + 1)) return true;
	ch[s] = 0;
	if (solve(s + 1)) return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		e.push_back({ a,b });
	}
	cout << solve(1) << "\n";
}