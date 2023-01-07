#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s= "";
    bool check= false;

    cin >> s;
    string tmp= "";
    int sum=0;
    bool init=false;

    for ( char c: s){
        if(c == '+'){
            int a = stoi(tmp);
            if(check){
                sum -= a;
            }
            else{
                sum += a; 
            }
            tmp.clear();
        }
        else if(c == '-'){
            int a = stoi(tmp);
            if(check){
                sum -= a;
            }
            else{
                sum += a; 
            }
            check = true;
            tmp.clear();
        }
        else{
            tmp += c;
        }
    }
    int a = stoi(tmp);
    if(check){
        sum-=a;
    }
    else{
        sum +=a;
    }
    cout << sum << "\n";
}