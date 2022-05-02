#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int n;
vector<int> arr;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) arr.push_back(i + 1);
    do {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
}