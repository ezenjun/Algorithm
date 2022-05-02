#include <iostream>


using namespace std;

int main(){
    int N, answer=0, cnt=0;
    cin >> N;
    for(int i=0; i< N; i++){
        int tmp;
        cin >> tmp;
        for(int j = 1; j<= tmp; j++){
            if(tmp%j ==0)
                cnt ++;
        }
        if(cnt == 2){
            answer++;
        }
        cnt = 0;
    }
    cout << answer << endl;
}