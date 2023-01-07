#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unsigned int N,K;
    vector<int> arr;

    cin >> K >> N;
    for(int i=0; i<K; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    unsigned int start, end, mid;
    unsigned int count=0;
    unsigned int result=0;
    start = 1;
    end = arr[K-1];
    while(start <= end){
        count=0;
        mid = (start + end) / 2;
        for(int i=0; i<K; i++){
            count += (arr[i]/mid);
        }
        if(N <= count){
            start = mid + 1;
            result = max(result, mid);
        }
        else{
            end = mid -1;
        }
    }
    cout << result << "\n";
}