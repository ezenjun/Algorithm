#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    int v[100001];
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int start = 0, sum = 0;
    int maxSum = -99999999;
    for (int i = 0; i < N; i++)
    {
        sum += v[i];
        if (i >= K - 1)
        {
            maxSum = max(maxSum, sum);
            sum -= v[start++];
        }
    }
    cout << maxSum << "\n";
}