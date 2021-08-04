#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 집으로부터 상하좌우로 m 내로 민초가 존재해야한다
// 집 좌표 저장
// 우유 좌표 저장
// 모든 점을 다 확인해서 다시 돌아와야한다
int arr[11][11];
int ans = 0 , n, m ,h;
pair<int,int> home;
vector<pair<int,int>> milk;
bool visited[11]={false,};

void dfs(int x, int y, int m, int depth){
    if(m >= abs(x - home.first) + abs(y - home.second)){ //거리보다 체력이 크면
        ans = max(depth, ans);
    }
    if (depth == milk.size()) return;//다 확인했으면
    for(int i=0; i<milk.size(); i++){
        if(!visited[i]){//우유와의 거리 구해보기
            int milkdist = abs(x - milk[i].first) + abs(y - milk[i].second);
            if(milkdist > m)continue;//체력보다 거리가 멀면 어차피 못감
            visited[i] = true;
            dfs(milk[i].first, milk[i].second, m + h - milkdist, depth + 1);
            visited[i] = false;
        }
    }


}

int main(){
    cin>> n >> m >> h;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){//집
                home.first = i;
                home.second = j;
            }
            else if (arr[i][j] == 2){//우유
                milk.push_back(make_pair(i,j));
            }
        }
    }
    dfs(home.first, home.second,m,0);
    cout << ans << "\n";
}