#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
int arr[9] = {0,};
bool visited[9] = {0,};
vector<int> v;

void backTrack(int cnt){
    if(cnt == m){
        for(int i=0; i< m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i< v.size(); i++){
        if(visited[i]){continue;}
        visited[i] = true;
        arr[cnt] = v[i];
        backTrack(cnt+1);
        visited[i] = false;
    }
}

int main(){
    
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    backTrack(0);
    return 0;
}