#include <iostream>
#include <string.h>

using namespace std;

int M,N,K;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int map[50][50]={0};
int visited[50][50]={0};


void dfs(int j, int k){
    for(int i=0; i<4; i++){
        int nx = k + dx[i];
        int ny = j + dy[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M)
            continue;
        if(map[ny][nx] && !visited[ny][nx]){
            visited[ny][nx]++;
            dfs(ny,nx);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,X,Y;
    cin >> T;
    for(int i=0; i<T; i++){ //Test case
        cin >> M >> N >> K;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        int ans = 0;
        for(int j=0; j<K; j++){
            cin >> X >> Y;
            map[Y][X] = 1;
        }
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++)
                if(map[j][k] && !visited[j][k]){
                    ans++;
                    visited[j][k]++;
                    dfs(j,k);
                }
        cout << ans << "\n";
    }
}