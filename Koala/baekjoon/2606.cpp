#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, cnt = 0;
vector<int> map[101];
bool visited[101];

void dfs(int n){
    visited[n] = true;
    for(int i=0; i<map[n].size(); i++){
        int next = map[n][i];
        if(!visited[next]){
            dfs(next);
            cnt++;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M ;i++){
        int start, end;
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }
    dfs(1);
    cout << cnt << "\n";
}