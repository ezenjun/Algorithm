#include <iostream>
#include <algorithm>

using namespace std;

int n, start;
int map[11][11];
int mincost = 987654321;
bool visited[11];

void dfs(int visit, int cnt, int cost){
    if(cnt == n){
        if(map[visit][start] > 0){
            mincost = min(mincost, cost + map[visit][start]);
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(map[visit][i] == 0)continue;
        if(visited[i] == true)continue;

        visited[i]=true;
        dfs(i,cnt+1,cost+map[visit][i]);
        visited[i]=false;
    }
}

int main(){
    cin >> n; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        start = i;
        visited[i] = true;
        dfs(i,1,0);
        visited[i] = false;
    }
    cout << mincost << "\n";
}