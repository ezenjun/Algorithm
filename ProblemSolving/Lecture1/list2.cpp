#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> A;
    A.push_back(1);
    A.push_back(4);
    A.push_back(5);
    //auto를 사용하면 훨씬 간단
    for (auto a: A){
        cout << a << endl;
    }
    return 0 ;
}