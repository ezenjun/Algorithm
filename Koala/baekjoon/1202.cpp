#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K;
priority_queue<int> pq;
long long answer = 0;

int main(){
    cin >> N >> K;
    vector<pair<int,int>> jewlery(N);
    vector<int> bag(K);
    for(int i=0; i<N; i++){
        int m,v;
        cin >> jewlery[i].first >> jewlery[i].second;
    }
    sort(jewlery.begin(), jewlery.end());
    for(int i=0; i<K; i++){
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end());
    int idx = 0;
    for(int i=0; i<K; i++){
        while(idx < N && jewlery[idx].first <= bag[i]){
            pq.push(jewlery[idx++].second);
        }
        if(!pq.empty()){
            answer += (long long)pq.top();
            pq.pop();
        }
    }
    cout << answer << "\n";
}