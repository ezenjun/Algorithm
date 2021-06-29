#include <iostream>
#include <algorithm>
using namespace std;

int d[1001], a[10001];

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(d[i], a[j] + d[i-j]);
        }
    }
    cout << d[n] << "\n";
}