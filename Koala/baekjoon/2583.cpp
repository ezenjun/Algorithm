#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,K;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int map[101][101];
bool visited[101][101];
int cnt;
vector<int> res;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> M >> N >> K;
    for(int i=0; i<K; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1 ;j<y2; j++){
            for(int k=x1; k<x2; k++){
                map[j][k] =  1;
                visited[j][k] = true;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0 && visited[i][j] == false) {
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    int size = res.size();

    cout << size << endl;
    for (int i = 0; i < size; i++)
        cout << res[i] << endl;
    return 0;
}