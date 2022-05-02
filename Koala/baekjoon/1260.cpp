#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> map[1001];
bool check[1001];

void dfs(int v){
    check[v] = true;
    cout << v << " ";
    for(int i=0; i<map[v].size(); i++){
        int next = map[v][i];
        if(!check[next])
            dfs(next);
    }

}

void bfs(int v){
    queue<int> q;
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(){
    int n,m,v;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }
    for(int i=1; i<=n; i++){
        sort(map[i].begin(), map[i].end());
    }
    dfs(v);
    cout<<"\n";
    memset(check, false, sizeof(check));
    bfs(v);

    return 0;
}