#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 일반 블록 - m 개의 색, black = -1 , rainbow = 0
// |r1 - r2| + |c1 - c2| = 1 을 만족하는 r1, c1 과 r2, c2를 인접한 칸이라고 한다
// 블록 그룹 - 연결된 블록의 집합
// 일반 블록이 적어도 하나 존재, 일반 블록의 색은 모두 같아야 한다.
// 검은색 block 포함 x , 무지개는 상관 x 
// 블록의 개수 >= 2
// 그룹 내의 블록은 모두 접근 가능해야함
// 기준 블록 = 무지개가 아닌 블록 중 행의 번호가 가장 작은 블록
// 그 중에서도 열의 번호가 가장 작은 블록


// 1.
// 크기가 가장 큰 블록 그룹을 찾는다
// 여러개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹
// 그것도 여러개면 기준 블록의 행이 가장 큰 것을
// 그것도 여러개면 열이 가장 큰 것

// 2.
// 1에서 찾은 블록그룹의 모든 블록을 제거
// 블록 그룹에 포함된 블록의 수 B 일떄 점수는 B^2

// 3.
// 격자에 중력이 작용

// 4.
// 격자가 90도 반시계 방향으로 회전

// 5.
// 다시 격자에 중력이 작용

int arr[21][21];
int n, m;

void rotate(){
    int rotated[n][n];
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
        	rotated[n-j-1][i] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
            arr[i][j] = rotated[i][j];
        }
    }
}

void gravity(){
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
            if(arr[i][j] >= 0){
                if(arr[i+1][j] == -2){
                    int k = i;
                    while(arr[k+1][j] == -2 && k < n){
                        k++;
                    }
                    arr[k][j] = arr[i][j];
                    arr[i][j] = -2;
                }
                else
                    continue;
            }
        }
    }
}

// void bfs(int start){ 
//     queue<int> q; 
//     q.push(start);
//     visit[start] = true;
//     while(!q.empty()){ // 큐에 값이 있을경우 계속 반복 실행 // 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다. 
//         int x = q.front();
//         q.pop();
//         for(int i=0; i< a[x].size();i++){ 
//             int y = a[x][i];
//             if(!visit[y]){ // 방문하지 않았다면.. q.push(y);
//                 // 색이 같은지 화인하고 무지개인지 확인하고 검정이 아닌거
//                 visit[y] = true;
//             } 
//         } 
//     } 
// }


int main(){
    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n ;j++){
            cin >> arr[i][j];
        }
    }
    gravity();
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n ;j++){
            cout <<  arr[i][j] << " ";
        }
        cout << "\n";
    }
}


// 1 0 5 -1 1
// -2 0 -2 -2 -2
// -2 -2 3 -2 -2
// 1 1 -2 -2 -2
// -2 5 -2 -2 2



// -2 0 -2 -1 -2
// -2 -2 5 -2 -2
// 1 0 -2 -2 -2
// -2 1 -2 -2 1
// 1 5 3 -2 2
