
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    for(int i=0 ;i < t; i++){
        int n; cin >> n;
        multiset<int> dq;
        for(int j= 0 ; j < n; j++){
            char c; int tmp;
            cin >> c >> tmp;
            if( c == 'I'){
                dq.insert(tmp);
            }
            else{
                if(dq.empty())continue;
                if(tmp == 1){
                    auto end = dq.end(); end --;
                    dq.erase(end);
                }
                else{
                    auto begin = dq.begin();
                    dq.erase(begin);
                }
            }
        }
        if(dq.empty()) cout << "EMPTY" << '\n';
        else{
            auto end = dq.end(); end --;
            cout << *end << ' ' << *dq.begin() << '\n';
        }
    }
}


// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <deque>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     int t; cin >> t;
//     for(int i=0 ;i < t; i++){
//         int n; cin >> n;
//         deque<int> dq;
//         for(int j= 0 ; j < n; j++){
//             char c; int tmp;
//             cin >> c >> tmp;
//             if( c == 'I'){
//                 dq.push_back(tmp);
//                 sort(dq.begin(), dq.end());
//             }
//             else{
//                 if(dq.empty())continue;
//                 if(tmp == 1){
//                     dq.pop_back();
//                 }
//                 else{
//                     dq.pop_front();
//                 }
//             }
//         }
//         if(dq.empty()) cout << "EMPTY" << '\n';
//         else{
//             cout << dq.back() << ' ' << dq.front() << '\n';
//         }
//     }
// }