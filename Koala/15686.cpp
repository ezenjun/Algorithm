#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> home, chicken;
//크기 NxN N(2 ≤ N ≤ 50)
// M(1 ≤ M ≤ 13)
int dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) //home
                home.push_back(make_pair(i,j));
            else if(map[i][j] == 2) //chicken
                chicken.push_back(make_pair(i,j));
        }
    }
}