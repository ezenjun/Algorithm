#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

int main(){
    int ans = -10000;
    int n; cin >> n;
    for(int i = 0 ;i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    do{
        int temp = 0;
        for(int i=1;i<n; i++){
            temp += abs(arr[i]-arr[i-1]);
        }
        if(temp>ans) ans = temp;
    }while(next_permutation(arr,arr+n));
    cout << ans << "\n";
}