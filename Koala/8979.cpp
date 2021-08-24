#include <iostream>
#include <algorithm>

using namespace std;

int medal[1001][4] = {0,};

int main(){
    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++){
        int country; cin >> country;
        for (int j = 1; j <= 3; j++) {
			cin >> medal[country][j];
		}
    }
    int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (medal[i][1] > medal[k][1]) cnt++; //금메달 수가 더 많은 나라 
		if (medal[i][1] == medal[k][1] && medal[i][2] > medal[k][2]) cnt++; //금메달 수가 같으면, 은메달 수가 더 많은 나라
		if (medal[i][1] == medal[k][1] && medal[i][2] == medal[k][2] && medal[i][3] > medal[k][3]) cnt++; //금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라 
	}
	cout << cnt << '\n';
}