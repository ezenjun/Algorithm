#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[51][51], N, M;
vector<pair<int,int>>house, chicken;
bool visited[13];
int minChicken;
int res = 987654321;
// 1. 입력
// 2. N-M개의 가게를 없애고 도시의 치킨거리를 구한다.
// 3. 2를 반복하면서 최소 값을 찾는다.

int distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void dfs(int idx, int selected){
    if(selected == M){ // M개의 가게를 확인
        int tmp=0;
        for(int i=0; i<house.size(); i++){
            int dist = 987654321;
            for(int j=0; j<chicken.size(); j++){
                if(visited[j])
                    dist = min(dist, distance(house[i], chicken[j]));
            }
            tmp += dist;
        }
        res = min(res, tmp);
        return;
    }
    if(idx == chicken.size())
        return;
    visited[idx] = true;
    dfs(idx+1, selected+1);
    visited[idx] = false;
    dfs(idx+1, selected);
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j]==1)
                house.push_back({i,j});
            else if (map[i][j]==2)
                chicken.push_back({i,j});
        }
    }
    res = 987654321;
    dfs(0,0);
    cout << res << "\n";
}