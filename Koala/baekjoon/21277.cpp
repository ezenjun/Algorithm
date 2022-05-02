#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mp1[51][51], mp2[51][51];
int ans[151][151];
int n1, n2, m1, m2;
int result  = 999999;

void rotate(){
    int tmp[51][51] = {0,};
    for(int i = m2-1;i >= 0; i--) {
        for(int j = 0; j < n2; j++) {
            tmp[m2 - 1 - i][j] = mp2[j][i];
        }
    }

    for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 50; j++) {
			mp2[i][j] = tmp[i][j];
		}
	}
    swap(n2,m2);
}


void check(int x, int y){
    bool check = true;
    for(int i = x; i < x + n2; i++){
        for(int j = y; j < y + m2; j++){
            if(ans[i][j] == 1 && mp2[i-x][j-y] == 1){
                check = false;
                break;
            }
        }
        if(check == false){
            break;
        }
    }
    if(check == true){
        int x1 = min(x,50);
        int x2 = max(x + n2-1, 49 + n1);
        int y1 = min(y,50);
        int y2 = max(y+ m2-1, 49 + m1);

        int area = (x2-x1+1) * (y2-y1+1);
        result = min(result, area);
    }

}


int main(){
    
    //1번 퍼즐
    cin >> n1>> m1;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1 ; j++){
            char tmp; cin>>tmp;
            mp1[i][j] = tmp - '0';
        }
    }
    //2번 퍼즐
    cin >> n2>> m2;
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2 ; j++){
            char tmp; cin>>tmp;
            mp2[i][j] = tmp - '0';
        }
    }

    //1번 퍼즐 고정
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1 ; j++){
            ans[50+i][50+j] = mp1[i][j];
        }
    }   
    // 0 90 180 270 돌려가면서 ans[50][50] 부터 ans[50+n1][50+m1] 다 확인
    for(int i = 0; i<4; i++){ //회전 4번
        //ans[0][0] 부터 다 확인
        for(int j = 0; j<100; j++){
            for(int k = 0 ; k < 100; k++){
                check(j, k);
            }
        }
        rotate();
    }
    
    cout << result << "\n";
    return 0;
}