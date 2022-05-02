#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, arr[101][101]={0,};
bool visited[101][101]={false,};
int ans=1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; 
int minval = 101, maxval = 0;

void dfs(int x, int y, int height){
    for(int i=0; i<4; i++){
        int newx = dx[i] + x;
        int newy = dy[i] + y;
        if(newx < 0 || newx >= n || newy < 0 || newy >= n) //벗어난 경우
            continue;
        if(arr[newx][newy] <= height || visited[newx][newy]) // 이미 확인됐거나 잠기는 경우
            continue;
        visited[newx][newy] = true;
        dfs(newx, newy, height);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            minval = min(minval, arr[i][j]);//가장 낮은 높이
            maxval = max(maxval, arr[i][j]);//가장 높은 높이
        }
    }
    
    for(int i=minval; i<maxval; i++){//비가 올 수 있는 모든 높이 확인
        int cnt=0;
        memset(visited,false,sizeof(visited)); // visited 초기화 해야 모든 높이 확인 가능
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[j][k] > i && !visited[j][k]){//모든 자리 확인
                    visited[j][k] = true;
                    cnt++;
                    dfs(j,k,i);
                }
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans << endl;
    return 0;

}