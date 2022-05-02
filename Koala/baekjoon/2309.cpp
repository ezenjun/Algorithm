#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[10], sum=0;
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr,arr+9);
    int odd1,odd2;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum - arr[i]-arr[j] == 100){
                odd1 = i;
                odd2 = j;
            }
        }
    }
    for(int i=0; i<9; i++){
        if(i==odd1 || i==odd2){
           continue;
        }
         cout << arr[i]<<endl;
    }



}