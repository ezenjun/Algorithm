#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[26][26];
bool visit[26][26];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int house, n;
vector<int> house_cnt;

void dfs(int x, int y){
    house++;
    visit[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(map[nx][ny] == 1 && visit[nx][ny] == false){
            dfs(nx,ny);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++)	
            map[i][j] = tmp[j] - '0';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && visit[i][j] != true){
                house = 0;
                dfs(i,j);
                house_cnt.push_back(house);
            }
        }
    }
    sort(house_cnt.begin(), house_cnt.end());
    cout << house_cnt.size() << "\n";
    for(int i=0; i<house_cnt.size(); i++){
        cout << house_cnt[i] << "\n";
    }
    return 0;
}