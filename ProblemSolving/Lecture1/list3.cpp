#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> lst;
    list<int>::iterator it;
    lst.push_back(1);
    lst.push_back(4);
    lst.push_back(5);
    //list 안의 처음 부터 마지막 까지 출력
    for(it = lst.begin(); it != lst.end(); it++){
        cout << *it << endl;
    }

    //list 2번째 원소 삭제
    it = lst.begin(); it ++; lst.erase(it);
    //list 안의 처음 부터 마지막 까지 출력
    for(it = lst.begin(); it != lst.end(); it++){
        cout << *it << endl;
    }

    //list 2번째에 10 추가
    it = lst.begin(); it ++; lst.insert(it, 10);
    //list 안의 처음 부터 마지막 까지 출력
    for(it = lst.begin(); it != lst.end(); it++){
        cout << *it << endl;
    }

    return 0;
}