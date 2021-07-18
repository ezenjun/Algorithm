#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 4000000;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    vector<int> prime;
    bool isPrime[MAX+1];
    fill(isPrime+2, isPrime+MAX+1, true);
    for(int i=2; i<=MAX; i++){
        if(isPrime[i]) prime.push_back(i);
        for(int j=i*2; j<=MAX; j+=i)
            isPrime[j] = false;
    }
    
    int N,M,result = 0, sum = 0, lo = 0, hi = 0;
    cin >> M;
    N = prime.size();
    while(1){
        if(sum >= M) sum -= prime[lo++];
        else if(hi == N) break;
        else sum += prime[hi++];
        if(sum == M) result++;
    }
    cout << result << "\n";
}