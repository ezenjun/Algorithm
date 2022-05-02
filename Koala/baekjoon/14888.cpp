#include <iostream>
#include <algorithm>

using namespace std;
int n, arr[11], operators[4];
int mini = 1000000001, maxi = -1000000001;

void find(int ans, int idx){
    if(idx == n){
        if(ans < mini)
            mini = ans;
        if(ans > maxi)
            maxi = ans; 
        return;
    }
    for(int i=0; i<4; i++){
        if(operators[i]>0){
            operators[i]--;
            if(i==0){//plus
                find(ans+arr[idx], idx+1);
            }
            else if(i==1){
                find(ans-arr[idx], idx+1);
            }
            else if(i==2){
                find(ans*arr[idx], idx+1);
            }
            else {
                find(ans/arr[idx], idx+1);
            }
            operators[i]++;
        }
    }
    return;
}


int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> operators[i];
    }
    find(arr[0],1);
    cout<<maxi<<endl;
    cout<<mini<<endl;
}