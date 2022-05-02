#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
char map[51][51];
bool visited[51][51];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans = 0;


void bfs(int x, int y){
    int cnt=0;
    memset(visited,0,sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int newx = curx + dx[j];
                int newy = cury + dy[j];

                if (!(0 <= newx && newx < n && 0 <= newy && newy < m)) continue;
                if (map[newx][newy] == 'W') continue;
                if (visited[newx][newy]) continue;
 
                q.push(make_pair(newx, newy));
                visited[newx][newy] = true;
            }
        }
        ++cnt;
    }
    if(ans<cnt-1)
        ans=cnt-1;

}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>>map[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]=='L')
                bfs(i,j);
        }
    }
    cout<<ans<<"\n";
    return 0;
}