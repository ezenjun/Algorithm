#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, result;
    map<int,int> rank;
    vector<int> mid;
    cin >> n;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        mid.push_back(input);
        rank.insert(make_pair(input,0));
    }
    // for(auto& x : rank){
    //     cout<< x.first << "," << x.second << endl;
    // }
    for(int i=0; i<n; i++){
        result = 0;
        for(map<int,int>::reverse_iterator iter = rank.rbegin(); iter!=rank.rend(); ++iter){
            if(iter->first == rank.find(mid[i])->first){
                (*iter).second+=1;
                break;
            }
            result += (*iter).second;
        }
        cout << result + 1 << endl;
    }
    return 0;
}