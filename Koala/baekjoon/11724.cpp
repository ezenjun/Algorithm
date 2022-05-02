#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> map[1001];
bool visited[1001];

void dfs(int n){
    visited[n] = true;
    for(int i=0; i<map[n].size(); i++){
        int next = map[n][i];
        if(!visited[next])
            dfs(next);
    }
}

int main(){
    cin >> N >> M;
    for(int i=0 ; i<M; i++){
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    int cnt = 0;
    memset(visited,false,sizeof(visited));
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}