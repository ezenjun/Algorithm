#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

#define INF 987654321;

int adj[201][201];
int route[201][201];


int main(){
    int n, m; cin>> n >> m;
    while(m--){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1][v2] = w;
        adj[v2][v1] = w;
    }

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if(i==j) continue;
            route[i][j] = j;
            if(!adj[i][j]){
                adj[i][j] = INF;
            }
        }
    }

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            for(int k = 1; k<=n; ++k){
                if(j==k) continue;
                if(adj[j][k] > adj[j][i] + adj[i][k]){
                    adj[j][k] = adj[j][i] + adj[i][k];
                    route[j][k] = i;
                }
            }
        }
    }

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if(i == j) continue;
            if(route[i][j] == j) continue;
            int current = j;
            while(route[i][current] != current){
                current = route[i][current];
            }
            route[i][j] = current;
        }
    }

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=n; ++j){
            if(i==j){
                cout << '-';
            }
            else{
                cout << route[i][j];
            }
            if(j==n){
                cout << "\n";
            }
            else{
                cout << ' ';
            }
        }
    }

}