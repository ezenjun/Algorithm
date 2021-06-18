#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> A;
    list<int>::iterator it;
    A.push_back(1);
    A.push_back(4);
    A.push_back(5);
    //list 안의 처음 부터 마지막 까지 출력
    for( it = A.begin(); it!=A.end(); it++){
        cout<<*it<<endl;
    }

    //list 안의 마지막 부터 처음까지 출력
    it = A.end();
    it --;
    while(it!=A.begin()){
        cout<<*it<<endl;
        it--;
    }
    
    cout<<*it<<endl;
    return 0;
}