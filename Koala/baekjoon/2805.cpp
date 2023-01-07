#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, M, max=-1;
    long long start, end, mid, sum;
    vector<int> arr;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    start = 0;
    end = arr[N-1];

    while(start <= end){
        sum = 0;
        mid = (start + end) / 2;
        for(int i=0; i<N; i++){
            if(arr[i] - mid > 0)
                sum += arr[i]-mid;
        }
        if(sum >= M){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else{
            end = mid -1;
        }
    }
    cout << max << "\n";
}