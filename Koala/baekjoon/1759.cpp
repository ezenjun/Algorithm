#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> v;
vector<char> ans;
int L, C;

bool compatible(){
    int vowel = 0;
    for(int i=0; i<L; i++){
        if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] =='u'){
            vowel++;
        }
    }
    if(vowel>=1 && L-vowel >=2) 
        return true;
    else 
        return false;
}

void dfs(int depth){
    if(ans.size() == L){
        if(compatible()){
            for(int i=0; i<L; i++){
                cout << ans[i];
            }
            cout << '\n';
            return;
        }
    }
    for(int i = depth ; i< C; i++)
    {
        ans.push_back(v[i]); 
        dfs(i+1);
        ans.pop_back();
    }
    return;
}

int main(){
    cin >> L >> C;
    for(int i=0; i<C; i++){
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0);
}