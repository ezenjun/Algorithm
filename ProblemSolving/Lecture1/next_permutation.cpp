#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[] = {0,1,2};
    do{
        for(int i=0; i<3; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }while(next_permutation(a,a+3));
    cout << endl;

    a[0] = 2; a[1] = 1; a[2] = 0;
    do{
        for(int i=0; i<3; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }while(prev_permutation(a,a+3));

    return 0;
}