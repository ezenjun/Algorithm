#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string name[100001];
    map<string,int> map;
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        name[i]=s;
        map.insert(make_pair(s,i));
    }
    for(int i=0; i<m; i++){
        string s;
        int k;
        cin >> s;
        if(isdigit(s[0])){
            k = stoi(s);
            cout << name[k] << '\n';
        }
        else{
            cout <<map.find(s)->second <<'\n';
        }
    }
}