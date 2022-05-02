#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>> n;
    int arr[1002], dp[1002];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[i] = 100000;
    }
    dp[0] = 0;
    for(int i = 0; i< n; i++){  //처음부터 끝까지
        for(int j =1; j <= arr[i]; ++j){ // 1 ~ arr[i] 만큼 점프한걸 다 비교
            if(i + j >= n){ //마지막까지 갔거나 넘어가면 마지막에 도달 가능
                break;
            }
            if(dp[i+j] > dp[i] + 1){   //다음 자리의 결과가 이전 자리 결과보다 크다
                dp[i+j] = dp[i] + 1;    // 이전 결과를 dp에 저장
            }
        }
    }
    if(dp[n-1] == 100000){
        dp[n-1] = -1;
    }
    cout << dp[n-1];
}