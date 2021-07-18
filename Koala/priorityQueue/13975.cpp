#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    for(int i=0 ;i < t; i++){
        priority_queue< long long, vector<long long>, greater<long long> > pq;
        int n; cin >> n;
        for(int j=0; j< n; j++){
            int tmp; cin >> tmp;
            pq.push(tmp);
        }
        long long sum = 0; 
        if(pq.size() == 1){ 
            cout << 0 << '\n'; 
            return 0; 
        }

        while(!pq.empty()){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            sum += a + b;
            if(pq.empty())break;
            pq.push(a + b);
        }

        cout << sum <<'\n';
    }

	return 0;

}