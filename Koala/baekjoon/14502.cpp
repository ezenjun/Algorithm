#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 1. 입력
// 2. map을 복사한 후 벽을 세운다(3번)
// 3. 바이러스를 퍼트린다(bfs)
// 4. 안전구역(0을) 센다
// 5. 안전구역의 max를 결정한다.
// 6. 2~4를 (M,M) 까지 반복한다 

int n, m;
int map[8][8], tmp[8][8];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans = 0;

void mapCopy(int (*a)[8], int (*b)[8]){
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            a[i][j] = b[i][j];
} 

void bfs(){
    int after[8][8];
    mapCopy(after, tmp);
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(after[i][j] == 2)
                q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(after[nx][ny] == 0 ){
                    after[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(after[i][j] == 0)
                cnt+=1;
        }
    }
    ans = max(cnt, ans);
}

void wall(int wall_cnt){
    if(wall_cnt == 3){
        bfs();
        return;
    }
        
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0){
                tmp[i][j] = 1;
                wall(wall_cnt+1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                mapCopy(tmp,map);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j]= 0 ;
            }
        }
    }
    cout << ans << "\n";
}