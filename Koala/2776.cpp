#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n,m;
        vector<int> v1;
        cin>> n; 
        while(n--){
            int a;
            cin >> a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        cin>> m; 
        while(m--){
            int b;
            cin >> b;
            if (binary_search(v1.begin(), v1.end(), b))
				cout << "1"<<"\n";
			else
				cout << "0"<<"\n";
        }

    }
}