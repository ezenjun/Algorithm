#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, sum;
    vector<int> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> sum;
    sort(arr.begin(),arr.end());

    int ans = 0, start = 0, end=n-1;
    while(start<end) {
        if(arr[start]+arr[end]==sum) {
            ans++;
            end--;
        } else if(arr[start] + arr[end]>sum) {
            end--;
        } else {
            start++;
        }
    }
    cout << ans << "\n";
}