#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double kim, lim; 

int main(){
    cin >> n >> kim >> lim;
    int cnt=0;
    while(kim!=lim){
        kim = ceil(kim/2);
        lim = ceil(lim/2);
        cnt++;
    }
    cout << cnt << "\n";
}