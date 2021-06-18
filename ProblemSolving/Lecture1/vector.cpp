#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> A;
    vector<int>::iterator it;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    
    //iterator 사용 방식
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << endl;
    
    //index 사용방식 - 더 많이 사용
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << endl;

    return 0;
}