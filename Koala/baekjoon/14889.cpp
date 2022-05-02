#include <iostream>
#include <algorithm>

using namespace std;
int n, ans=1000000000;
int arr[21][21];
bool check[22];

void dfs(int cnt, int next){
    if(cnt == n/2){
        int start=0, link=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(check[i] == true && check[j] == true)
                    start += arr[i][j];
                if(check[i] == false && check[j] == false)
                    link += arr[i][j];
            }
        }
        int tmp = abs(start-link);
        if(ans>tmp)
            ans = tmp;
        return;
    }
    for(int i=next; i<n; i++){
        check[i] = true;
        dfs(cnt+1, i+1);
        check[i] = false;
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,1);
    cout << ans << endl;

}