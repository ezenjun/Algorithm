#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int arr[10][10];
bool row[9][10] = { false };
bool col[9][10] = { false };
bool square[9][10] = { false };
// 1,1 부터 9,9까지 모두 확인 (0인 것만 다 확인)
// 각 좌표마다 가로, 세로, 3*3 확인= i/3, j/3으로 구분

void back_track(int depth){// 1.기저조건으로 stop 2. 조건 수행 - 안에서 arr 바꿔주고 backtrack(cnt+1) 하고 나서 이전 값으로 초기화해줘야함
    int x = depth % 9;
    int y = depth / 9;
    if(depth == 81){    //기저조건
        for(int i=0; i< 9; i++){
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j];//출력
            }
            cout << "\n";
        }
        exit(0);
    }
    if(arr[y][x] != 0){
        back_track(depth + 1);
    }
    else{
        for(int i = 1; i <=9; i++){ //1부터 9까지 다 넣어보면서 확인
            if(row[y][i] == false && col[x][i] == false && square[(y / 3) * 3 + (x / 3)][i] == false){  //가로 세로 사각형 안에 없으면
                row[y][i] = true;
                col[x][i] = true;
                square[(y / 3) * 3 + (x / 3)][i] = true;    //다 true로 만들고

                arr[y][x] = i;  //arr에 저장
                back_track(depth + 1);  // backtrack
                
                arr[y][x] = 0;  //arr 다시 0으로 만들어준다
                row[y][i] = false;
                col[x][i] = false;
                square[(y / 3) * 3 + (x / 3)][i] = false;   //다시 false로 만들고
            }
        }
    }
    return;

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++){ 
			arr[i][j] = str[j] - '0';
            if(arr[i][j] != 0){
                row[i][arr[i][j]] = true;//가로
				col[j][arr[i][j]] = true;//세로
				square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;//사각형
            }
        }
	}

    back_track(0);
}
