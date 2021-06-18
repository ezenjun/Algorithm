#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int myints[] = {1,2,3,4,4,4,4,10,11,15,16};
    vector<int> v;
    vector<int>::iterator low, hi;
    for(auto temp: myints)
        v.push_back(temp);

    sort(v.begin(), v.end());

    //4의 시작 
    low = lower_bound(v.begin(), v.end(), 4);

    //4의 마지막 
    hi = upper_bound(v.begin(), v.end(), 4);

    //4의 시작 index 반환
    cout << (low-v.begin()) << endl;
    //4의 마지막 index 반환
    cout << (hi-v.begin()) << endl;
    return 0;
}