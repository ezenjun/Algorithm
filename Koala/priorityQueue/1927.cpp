#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue< int, vector<int>, greater<int> > pq; //minheap
    int n; cin >> n;
    for(int i =0 ;i <n ;i++){
        long tmp; cin >> tmp;
        if(tmp != 0){
            pq.push(tmp);
        }
        else{
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}