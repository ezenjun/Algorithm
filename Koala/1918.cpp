#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string line;
    stack<char> s;
    cin >> line;

    for(int i=0 ;i < line.length(); i++){
        if(line[i] == '*' || line[i] == '/'){
            if(!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }
            s.push(line[i]);
        }
        else if(line[i] == '+' || line[i] == '-'){
            if(s.empty()){
                s.push(line[i]);
            }
            else{
                while(!s.empty()){
                    if(s.top() == '('){
                        break;
                    }
                    cout << s.top();
                    s.pop();
                }
                s.push(line[i]);
            }
        }
        else if(line[i] == '('){
            s.push(line[i]);
        }
        else if(line[i] == ')'){
            while(s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else{   // A ~ Z
            cout << line[i];
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}