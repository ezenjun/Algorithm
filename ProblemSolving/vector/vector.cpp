#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A[] = {3,1,4,1,5,9,2};
    vector<int> v;
    for(auto a: A){
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(auto a: v)
        cout << a <<"\n";
}