#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,sum,part;
    cin >> n;
    for(int i=1; i<=n; i++){
        sum = i;
        part = i; 
        while(part){
            sum+=part%10;
            part/=10;
        }
        if(n==sum){
            cout << i << endl;
            return 0;
        }
    }
    cout << '0' << endl;
}