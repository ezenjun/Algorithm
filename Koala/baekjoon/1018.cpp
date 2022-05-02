#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string white[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string black[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];

int white_count(int x, int y){
    int cnt = 0; 
    for(int i=0; i< 8; i++){
        for(int j=0; j< 8; j++){
            if(board[x+i][y+j] != white[i][j])
                cnt++;
        }
    }
    return cnt;
}

int black_count(int x, int y){
    int cnt = 0; 
    for(int i=0; i< 8; i++){
        for(int j=0; j< 8; j++){
            if(board[x+i][y+j] != black[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main(){
    int n,m;
    
    cin >> n >> m;
    for(int i=0 ; i<n; i++){
        cin >> board[i];
    }
    int count = 10000;
    for(int i=0 ; i+8<=n; i++){
        for(int j=0 ; j+8<=m; j++){
            int tmp;
            tmp = min(white_count(i,j),black_count(i,j));
            if(tmp < count)
                count = tmp;
        }
    }
    cout << count << endl;
}