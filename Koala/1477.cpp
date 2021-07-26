#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m ,l; cin >> n >> m >> l;
    vector<int> v(n);
    for(int i = 0; i< n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    priority_queue<pair<double, int>> dist;
    dist.push({v[0],1}); //0 ~ 처음 구간
    for(int i = 0; i< n-1; i++){
        dist.push({v[i+1]-v[i], 1});
    }
    dist.push({l - v[n-1], 1}); //마지막 휴게소 ~ 고속도로 마지막

    while(m--){
        double maxlen = dist.top().first;
        int section = dist.top().second;
        dist.pop();
        dist.push({(maxlen*section) / (section+1) , section+1});
    }

    double ans = dist.top().first;
  
    if(int(ans) == ans){
        cout << int(ans) <<"\n";
    }
    else{
        cout << int(ans) + 1 <<"\n";
    }
    return 0;
}