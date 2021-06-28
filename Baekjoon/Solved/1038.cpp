#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

void sol(ll index, int cnt){
    if(cnt > 10) return;
    v.push_back(index);
    for(int i=0; i<10; i++){
        if(index % 10 > i){
            sol(index*10 + i, cnt + 1);
        }
    }
    return;
}

int main(){
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i=0; i<10; i++){
        sol(i, 1);
    }
    sort(v.begin(), v.end());
    ll result = (v.size() <= n) ? -1: v[n];
    cout << result <<"\n";
    return 0;
}