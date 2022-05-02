#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n, count = 0, ans=0;
    cin >> n;
    while(count != n){
        ans++;
        int tmp = ans;
        while(tmp!=0){
            if(tmp %1000 == 666){
                count++;
                break;
            }
            else{
                tmp /=10;
            }
        }
    }
    cout << ans << endl;
}