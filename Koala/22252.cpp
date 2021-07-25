#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <functional>

using namespace std;


// 어떤 이름을 가진 고릴라가 , , ...,  만큼의 가치가 있는 정보 k 개를
// 가치 순으로 가장 비싼 정보들을 구매
// 1번 거래한 정보는 호석이에게 더 이상 가치가 없기 때문에 고릴라도 그 정보를 파기
// 1 Name   : 이름이 [Name]k, Ck인 고릴라가  b개의 정보를 얻었으며, 각 가치는  c1부터 ck 이다.
// 1로 시작하는 경우에는 정보를 얻은 정보 고릴라의 이름과  가 주어지며 이어서  개의 정보 가치 가 자연수로 주어진다
// 2 Name  : 호석이가 이름이 [Name]인 고릴라에게  개의 정보를 구매한다. 이때 고릴라가 가진 정보들 중 가장 비싼  개를 구매하며, 고릴라가 가진 정보가 개 이하이면 가진 모든 정보를 구매한다.
// 2로 시작하는 경우에는 호석이가 거래하려는 정보 고릴라의 이름과 구매하려는 정보의 개수 b가 주어진다. 


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, priority_queue<int>> query;
    long long ans = 0;
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int type; cin >> type;
        string name; int k, b;
        if(type == 1){
            cin >> name >> k;
            for(int j = 0; j<k; j++){
                int tmp; cin >> tmp;
                query[name].push(tmp);
            }
        }
        else{
            cin >> name >> b;
            while(!query[name].empty() && b!=0){
                ans += query[name].top();
                query[name].pop();
                b--;
            }
        }
    } 
    cout << ans << "\n";
}