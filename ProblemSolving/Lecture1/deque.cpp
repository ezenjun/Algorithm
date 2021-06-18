#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<double> dq;
    dq.push_front(1.1);
    dq.push_front(2.2);
    dq.push_front(3.3);

    for(auto i = 0; i < dq.size(); i++){
        cout << dq[i] << endl;
        dq.pop_front();
    }
    for(auto i = 0; i < dq.size(); i++){
        cout << "after pop" <<endl;
        cout<<dq[i]<<endl;
    }
    return 0;
}