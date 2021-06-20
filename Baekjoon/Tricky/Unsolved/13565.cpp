#include <iostream>
#include <algorithm>
using namespace std;

int yy[] = {-1, 0, 1, 0}, xx[] = {0, 1, 0, -1};
int N, M; 
int A[1001][1001]; 
bool V[1001][1001];

void dfs(int y, int x)
{
    V[y][x] = 1;
    for (int i=0;i<4;i++){
        int ny = y + yy[i], nx = x + xx[i];
        if (ny < 1 || ny > N || nx < 1 || nx > M || A[ny][nx] || V[ny][nx]) continue;
        dfs(ny, nx);
    }
}
int main()
{
    cin >> N >> M;
    //배열 입력
    for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) scanf("%1d", A[i]+j); 
    //dfs
    for (int i=1;i<=M;i++) if (!V[1][i] && !A[1][i]) dfs(1, i);
    bool ans = 0;
    for (int i=1;i<=M;i++) ans |= V[N][i];
    puts(ans ? "YES" : "NO");
}