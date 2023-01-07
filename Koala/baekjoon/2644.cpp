#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, find1, find2, m;
vector<int> v[101];
int visited[101];
int result = -1;

void dfs(int now, int end, int num){
    visited[now] = 1;
	if (now == end) {
		result = num;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!visited[next]) {
			dfs(next, end, num+1);
		}
	}
}

int main(){
    cin >> n >> find1 >> find2 >> m;
    for(int i=0; i<m; i++){
        int x, y; 
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
    dfs(find1, find2, 0);
	if (result != 0) {
		cout << result;
	}
	else cout << "-1";
}