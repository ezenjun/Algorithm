#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int n; cin >> n;
    v.resize(n);
    for(int i=0 ;i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(n%2 == 0){
        cout << v[n/2 - 1];
    }
    else{
        cout << v[n/2];
    }
}
