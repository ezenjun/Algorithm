#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[100001];

void binarySearch(int n, int arr[]){
    int start = 0;
    int end = N-1;
    int mid;

    while(start<=end){
        mid = (start + end) / 2;
        if(arr[mid] == n){
            cout << "1" << "\n";
            return;
        }
        else if(arr[mid] > n){
            end = mid -1;
        }
        else if(arr[mid] < n){
            start = mid + 1;
        }
    }
    cout << "0" << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    cin >> M;
    for(int i=0; i<M; i++){
        int num;
        cin >> num;
        binarySearch(num, arr);
    }
}