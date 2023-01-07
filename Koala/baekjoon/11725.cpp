#include <iostream>
#include <vector>

using namespace std;

vector<int> t[100001];
bool visited[100001];
int parent[100001];

void dfs(int start){
    visited[start] = true;
    for(int i=0; i<t[start].size(); i++){
        int next = t[start][i];
        if(!visited[next]){
            parent[next] = start;
            dfs(next);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int start, end;
        cin >> start >> end;
        t[start].push_back(end);
        t[end].push_back(start);
    }
    dfs(1);
    for(int i=2; i<=n; i++){
        cout << parent[i] << "\n";
    }
    return 0;
}