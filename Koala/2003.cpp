#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, arr[10001];
    cin >> n >> m;

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }

    int ans = 0, sum = 0, lo = 0, hi = 0;
    while(1){
        if(sum >= m) 
            sum -= arr[lo++];
        else if(hi == n)
            break;
        else
            sum += arr[hi++];
        if(sum == m)
            ans++;
    }
    cout << ans << "\n";
}