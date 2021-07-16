#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>> n >> q;
    vector<string> log[7];

    // 로그
    for(int i=0; i<n; i++){
        string date, timelv, tmp="";
        cin >> date >> timelv;
        for(int j=0 ; j< date.size(); j++){
            if(date[j] != '-'){
                tmp += date[j];
            }
        }
        for(int j=0 ; j< timelv.size()-2; j++){
            if(timelv[j] != ':'){
                tmp += timelv[j];
            }
        }
        int lv = timelv[timelv.size()-1] -'0';
        for(int k=1;k<=lv;k++)log[k].push_back(tmp);
    }

    // Query
    
    for(int i=0 ;i<q; i++){
        string startQuery, endQuery;
        string first, mid, last, s1="",s2="";
        int ans=0;
        int lvcheck;
        cin >> first >> mid >> last;
        for(int j=0 ; j< first.size(); j++){
            if(first[j] != '-'){
                s1 += first[j];
            }
        }
        for(int j=0 ; j< mid.size(); j++){
            if(mid[j] != ':' && j < 8){
                s1 += mid[j];
            }
            else if(mid[j] != '-' && j>8){
                s2 += mid[j];
            }
        }
        for(int j=0 ; j< last.size()-2; j++){
            if(last[j] != ':'){
                s2 += last[j];
            }
        }
        startQuery = s1;
        endQuery = s2;
        lvcheck = last[last.size()-1] -'0';
    
        int upperbound = upper_bound(log[lvcheck].begin(), log[lvcheck].end(), endQuery) - log[lvcheck].begin();
        int lowerbound = lower_bound(log[lvcheck].begin(), log[lvcheck].end(), startQuery) - log[lvcheck].begin();
        ans = upperbound - lowerbound;
        cout << ans << '\n';
    }

}