#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int e,s,m;
    int cnt=0;
    cin >> e >> s >> m;
    while(1){
        cnt++;
        if((cnt-e)%15 ==0 &&  (cnt-s)%28 ==0 && (cnt-m)%19==0){
            cout << cnt << "\n";
            break;
        }
    }
}