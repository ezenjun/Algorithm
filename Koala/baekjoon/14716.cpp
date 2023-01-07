#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M,N;
int dy[8] = { 0,0,-1,1,-1,-1,1,1 };
int dx[8] = { 1,-1,0,0,-1,1,-1,1 };
int map[251][251];
bool visited[251][251];
int answer = 0;

void dfs(int y, int x){
    visited[y][x]= true;
    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=M || nx>=N)
            continue;
        if(map[ny][nx] == 1 && visited[ny][nx] == false){
            visited[ny][nx] = true;
            dfs(ny,nx);
        }
    }
}

int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j< N; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j< N; j++){
            if(map[i][j]== 1 && visited[i][j]==false) {
                dfs(i,j);
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}