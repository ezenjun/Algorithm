#include <iostream>
#include <algorithm>

using namespace std;

int han(int n){
    int h,t,o, cnt=0;
    if(n < 100)
        return n;
    else{
        for(int i=100; i<= n; i++){
            h = i/100;
            t = (i%100)/10;
            o = (i%100)%10;
            if(h-t == t-o)
                cnt++;
        }
        return 99+cnt;
    }
}

int main(){
    int n;
    cin >> n;
    cout << han(n) << endl;
}