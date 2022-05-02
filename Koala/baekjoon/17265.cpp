#include <iostream>
#include <algorithm>
using namespace std;

int n, minimum=10000, maximum=-10000;
int dx[] = { 1, 0 }; 
int dy[] = { 0, 1 }; 
char map[6][6];


void search(int x, int y, int result, char prev){
    for (int i = 0; i < 2; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
        if(0 <= newx && newx <= n && 0 <= newy && newy <= n){
            if (map[newx][newy] == '+') { 
				search(newx, newy, result, '+');
			}
			else if (map[newx][newy] == '-') { 
				search(newx, newy, result, '-');
			}
			else if (map[newx][newy] == '*') { 
				search(newx, newy, result, '*');
			}
			else { //숫자
				int check; 
				if (prev == '+') { 
					check = result + (map[newx][newy] - '0');
				}
				else if (prev == '-') { 
					check = result - (map[newx][newy] - '0');
				}
				else if (prev == '*') { 
					check = result * (map[newx][newy] - '0');
				}
				if (newx == n-1 && newy == n-1) { 
					maximum = max(maximum, check); 
					minimum = min(minimum, check); 
					return; 
				}
				search(newx, newy, check, map[newx][newy]);
			}
        }
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    search(0,0,map[0][0] - '0', map[0][0]);

    cout << maximum << ' ' << minimum << endl;

}