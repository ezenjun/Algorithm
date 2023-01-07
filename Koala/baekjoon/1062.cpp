#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<string> arr;
bool alpha[26]={false,};
int ans = 0;

void search(int cnt, int idx){
    if(cnt == K-5){
        int cnt= 0;
        for(string str:arr){
            bool read = true;
            for(char c: str){
                int x= c-'a';
                if(alpha[x])continue;
                else{
                    read = false;
                    break;
                }
            }
            if(read)cnt++;
        }
        ans = max(ans,cnt);
        return;
    }
    for(int i=idx; i<26; i++){
        if(alpha[i]==true)
            continue;
        alpha[i]= true;
        search(cnt+1, i);
        alpha[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    if(K<5) {
        cout << '0' << "\n";
        return 0;
    }
    alpha[0] = true;
    alpha[2] = true;
    alpha[8] = true;
    alpha[13] = true;
    alpha[19] = true;

    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        string sub = tmp.substr(4, tmp.size()-8);
        arr.emplace_back(sub);
    }
    search(0,0);
    cout << ans << "\n";

}