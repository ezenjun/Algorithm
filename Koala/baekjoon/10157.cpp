#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int C, R, k;
int cnt = 1, x=1, y=1, d=0;
int map[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main(){
    cin >> C >> R >> k;
    if(C*R < k){
        cout << '0' << "\n";
        return 0;
    }
    else{
        y = R - 1; x = 0;
        while (cnt < k) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= C || ny < 0 || ny >= R || map[ny][nx] != 0) 
            { 
                d = (d + 1) % 4; 
                continue; 
            }
            map[y][x] = cnt++;
            y = ny;
            x = nx;
        }
        cout << x + 1 << ' ' << R - y;
    }
    
}