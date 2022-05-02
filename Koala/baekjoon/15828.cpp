#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n, packet = 0;
    scanf("%d",&n);
    while(1){
        cin >> packet;
        if(packet == 0){
            q.pop();
        }else if(packet == -1){
            break;
        }else{
            if(q.size() < n)
                q.push(packet);
        }
    }
    if(q.empty())
        printf("empty");
    else{
        while(!q.empty()){
            printf("%d",q.front());
            q.pop();
        }
    }
}