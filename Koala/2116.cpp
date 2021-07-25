#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[10001][7];
    int ans = 0;
    for(int i = 0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][4] >> arr[i][5] >> arr[i][3];
    }  
    for(int i = 0; i<6; i++){ // 바닥 먼저 기준 잡는데 bruteforce로 다 해봐야함
        int bottom = i, res = 0, cnt = 0;
        while(cnt < n){ //총 주사위 갯수만큼 각 면마다 모두
            int val = 0;
            for(int j = 0; j<6; j++){  
                if(j != bottom && j !=(bottom+3)%6 && val < arr[cnt][j]){ //top,bottom이 아닌 숫자들 중 비교
                    val = arr[cnt][j]; //max val값 갱신
                }
            }
            res += val;
            if(cnt < n-1){
                int top = arr[cnt][(bottom+3)%6];
                for(int j = 0; j<6; j++){
                    if(top == arr[cnt+1][j]){
                        bottom = j;
                        break;
                    }
                }
            }
            cnt ++;
        }
        ans = max(ans, res);
    }
    
    cout << ans << "\n";
}   