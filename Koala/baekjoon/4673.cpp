#include <iostream>
#include <algorithm>

using namespace std;

int find(int n){
    int tmp = n;
    while(n>0){
        tmp += n%10;
        n/=10;
    }
    return tmp;
}

int main(){
    bool self[10001]={false,};
    int check;
    for(int i=1; i<10001; i++){
        check = find(i);
        if(check < 10001){
            self[check] = true;
        }
    }
    for(int i=1; i<10001; i++){
        if(self[i] == false)
            cout << i << endl;
    }
}