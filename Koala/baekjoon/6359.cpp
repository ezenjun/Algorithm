#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>

using namespace std;
bool dp[101];

int main(){
    int n;
    cin >> n;
    while(n--){
        memset(dp,0,sizeof(dp));
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j += i) {
                if (dp[j])
                    dp[j] = false;
                else
                    dp[j] = true;
            }
        }
        int count = 0;
        for (int i = 1; i <= m; i++) {
            if (dp[i]) count++;
        }
        cout << count << '\n';
    }
}