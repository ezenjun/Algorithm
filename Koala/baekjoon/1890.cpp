#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[101][101];
long long dp[101][101];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    dp[0][0] = 1;
    for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (map[x][y] == 0) continue;

			if (dp[x][y] != 0)
			{
				int ny = y + map[x][y];
				int nx = x + map[x][y];

				if(nx < N) dp[nx][y] += dp[x][y];
				if(ny < N) dp[x][ny] += dp[x][y];
			}
		}
	}
    cout << dp[N - 1][N - 1] << endl;
}