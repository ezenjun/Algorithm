#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;
typedef long long ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll arr[1001][1001];
    ll dist[1001][1001];
    int n; cin >> n;

    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 1; i<= n; i++){
        for(int j=1; j<= n; j++){
            cin >> arr[i][j];
        }
    }

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int> >, greater<tuple<ll, int, int> > >pq;
    pq.push(make_tuple(abs(arr[0][0] - arr[0][1]), 0, 1));
	pq.push(make_tuple(abs(arr[0][0] - arr[1][0]), 1, 0));

    dist[0][0] = 0;
    ll ans = 0;
    

}