#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue< int, vector<int>, greater<int> > pq;

    int n; cin >> n;
    for(int i=0; i< n; i++){
        int tmp; cin >> tmp;
        pq.push(tmp);
    }
	int sum = 0; 
    if(pq.size() == 1){ 
        cout << 0 << '\n'; 
        return 0; 
    }

	while(!pq.empty()){
		int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a + b;
        if(pq.empty())break;
		pq.push(a + b);
	}

	cout << sum <<'\n';

	return 0;

}