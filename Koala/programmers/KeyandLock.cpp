#include <string>
#include <vector>

using namespace std;

int N,M;
vector<vector<int>> map, key, lock;
bool answer;
void rotate(vector<vector<int>> key){
    vector<vector<int>> temp(M,vector<int>(M));
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){   
            temp[i][j] = key[j][M-i+1];
        }
    }
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            key[i][j] = temp[i][j];
        }
    }
}

void check(int x, int y){
    bool check = true;
    for(int i=y; i<y+M; i++){
        for(int j = x; j<x+M; j++){
            if(map[i][j] == 1 && key[i-x][j-y] ==1){
                check = false;
                break;
            }
        }
        if(check == false){
            break;
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    M = key.size();
    N = lock.size();
    map = vector<vector<int>> ((2*M + N),vector<int>(2*M + N));
    for(int i = M; i< N+M; i++){    //map 가운데에다가 lock 위치시킨다
        for(int j = M; j<M+N; j++){
            map[i][j] = lock[i-M][j-M];
        }
    }
    for(int i = 0; i< M+N; i++){    //0부터 M+N 까지 모두 탐색
        for(int j = 0; j< M+N; j++){
            for(int k = 0; k < 4; k++){ //회전시켜가며 확인하다가 true면 리턴
                rotate(key);
                check(i,j);
            }
        }
    }
    
    return answer;
}