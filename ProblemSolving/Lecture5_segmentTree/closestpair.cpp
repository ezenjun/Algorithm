#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> ans;

    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            ans.push_back((v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << "\n";
}
//이 방법은 메모리초과 뜸 O(n^2 log n)