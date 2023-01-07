#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N, M;
    bool answer = true;
    priority_queue<int> pq;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        pq.push(c);
    }
    for(int i=0; i<M; i++){
        int w;
        cin >> w;
        if(pq.top() >= w){
            pq.push(pq.top()-w);
            pq.pop();
        }
        else
            answer = false;
    }
    cout << (answer? 1 : 0) << endl;
    
}