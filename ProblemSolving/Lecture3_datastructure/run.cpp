#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, result;
    vector<int> mid, rank;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        mid.push_back(input);
    }
    int max = *max_element(mid.begin(), mid.end());
    rank.resize(max,0);
    for(int i = 0; i< n; i++){
        result = 0;
        for(int j = max; j > mid[i]; j--){
            result += rank[j];
        }
        cout << result + 1 << endl;
        rank[mid[i]]++;
    }
}