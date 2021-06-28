#include <iostream>
#include <algorithm>
using namespace std;

int item[101][2], dp[101][100001];

int main(){
    int n, k; cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin >> item[i][0] >> item[i][1];
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-item[i][0] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-item[i][0]]+ item[i][1]) ;
            }
        }
    }
    cout << dp[n][k] << "\n";
}