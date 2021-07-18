#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // int n;cin >>n;
    // vector<int> v(2550000); 
    // for(int i=0; i<n*n; i++){
    //    cin >> v[i];
    // }
    // sort(v.begin(), v.end(), greater<int>());
    // cout << v[n-1];
    // 이 방법은 225만개의 수를 정렬하려면 225만 * log(225만) 인데 
    // 여기서 시간초과가

    int n;cin >>n;
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i = 0; i<n ;i++){
        for(int j = 0; j < n; j++){
            int tmp; cin >> tmp;
            if(i==0){
                pq.push(tmp);
            }
            else{
                pq.push(tmp);
                pq.pop();
            }
        }
    }
    cout << pq.top() << "\n";
    
}