#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string toBinary(int N)
{
    string r;
    while (N != 0){
        r += ( N % 2 == 0 ? "V" : "딸기" );
        N /= 2;
    }
    
    return r;
}

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << toBinary(N) << "\n";
    }
}