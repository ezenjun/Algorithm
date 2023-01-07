#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    vector<int> A;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N + M; i++)
    {
        cout << A[i] << " ";
    }
}