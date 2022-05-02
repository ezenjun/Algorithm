#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string a, b;
    int min = 50;
    int cnt =0;
    cin >> a;
    cin >> b;
    for(int leng=0; leng<=b.length() - a.length(); leng++){
        cnt =0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i+leng]) cnt++;
        }
        
        min = min>=cnt ? cnt:min;

    }
    cout<<min<<endl;
}