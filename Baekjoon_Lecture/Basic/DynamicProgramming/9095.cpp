#include <iostream>
using namespace std;

int d[12];

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int m; cin>>m;
        d[0] = 1; d[1] = 1; d[2] = 2;
        for(int j=3; j<=m; j++){
            d[j] = d[j-1] + d[j-2] + d[j-3];
        }
        cout << d[m] << "\n";
    }
}