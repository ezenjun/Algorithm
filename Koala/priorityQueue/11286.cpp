#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //minheap
    int n; cin >> n;
    for(int i =0 ;i <n ;i++){
        int tmp; cin >> tmp;
        if(tmp != 0){
            pq.push(make_pair(abs(tmp), tmp));
        }
        else{
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
}