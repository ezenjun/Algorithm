#include <iostream>
using namespace std;

int n, m; 
int arr[9];
//bool visited[9] = {0,};

void backTrack(int cnt){
    if(cnt == m){
        for(int i=0; i< m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        arr[cnt] = i;
        backTrack(cnt+1);
    }
}

int main(){
    
    cin >> n >> m;
    backTrack(0);
    return 0;
}
