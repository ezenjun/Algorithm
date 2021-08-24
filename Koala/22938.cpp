#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    long long x = abs(x1-x2);
    long long y = abs(y1-y2);
    long long r = r1 + r2;
    if(x*x + y*y < r*r){
        cout<<"YES"<<"\n";
    }
    else{
        cout << "NO"<<"\n";
    }
    return 0;

}