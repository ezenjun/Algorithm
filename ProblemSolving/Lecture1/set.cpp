#include <iostream>
#include <set>
using namespace std;

int main(){
    char str[] = {'a','b','c','d','e','f','g'};
    set<char> S; 
    set<char>::iterator it;
    
    //S에 str 원소 추가
    for(int i= 0 ; i < sizeof(str)/sizeof(char); i++){
        S.insert(str[i]); 
    }
    
    //S 출력
    for(it = S.begin(); it != S.end(); it++){
        cout << *it << endl;
    }
    //S에서 d의 위치를 it으로 저장하고 삭제 (index)
    it = S.find('d'); S.erase(it);

    //S에서 직접 a 찾아 삭제
    S.erase('a');

    
    //S 출력
    for (it = S.begin(); it != S.end(); it++){
        cout << *it << endl;
    }
    return 0;
}