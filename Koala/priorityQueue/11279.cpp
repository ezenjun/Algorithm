#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue< int, vector<int>, less<int> > pq; //maxheap
    int n; cin >> n;
    for(int i =0 ;i <n ;i++){
        int tmp; cin >> tmp;
        pq.push(tmp);
        if(tmp == 0){
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}