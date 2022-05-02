#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> c;
vector<pair<int, pair<int,int>>> p;
bool check[10000]={false,};

int sum=0, minimum =10000000;

void permutation(int depth){
    if(depth == n){
        if(sum < minimum){
            minimum = sum;
            minimum+=1;
        }
        sum=0;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!check[i]){
            check[i] = true;
            sum += c[i];
            while(!p[depth].second.first){
                if(p[depth].second.first == i){
                    if(c[i]- p[depth].second.second >0)
                        sum -= p[depth].second.second;
                    else
                        sum = sum -c[i] +1;
                }
            }
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int tmp;
        cin>>tmp;
        c.push_back(tmp);
    }
    for(int i=1; i<=n; i++){
        int cnt; 
        cin >> cnt;
        for(int j=1; j<=cnt; j++){
            int idx, discount;
            cin >> idx >> discount;
            p.push_back(make_pair(i,make_pair(idx,discount)));
        }
    }
    permutation(0);
    cout << minimum << endl;
}