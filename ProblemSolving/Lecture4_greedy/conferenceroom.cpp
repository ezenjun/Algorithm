#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int> &s1, const pair<int,int> &s2){
    if(s1.second != s2.second) return s1.second < s2.second;
    return s1.first < s2.first;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<pair<int, int>> ans;

    for (int i=0 ;i<n; i++){
        int start, end; cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), compare);
    int begin = -1;
    int cnt = 0;    
    for(auto x: v){
        if (x.first > begin){
            ans.push_back(x);
            cnt ++;
            begin = x.second;
        }
    }
    for(auto x: ans)
        cout<< "(" << x.first << "," << x.second << ")" << endl;
    cout << cnt << endl;
}