#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define MAX 100001
using namespace std;

int main()
{
    int n;
    int start, end;
    long long arr[MAX];
    long long mini = LLONG_MAX;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    start = 0;
    end = n - 1;
    int left, right;
    while (start < end)
    {
        long long sum = arr[start] + arr[end];
        if (llabs(sum) < mini)
        {
            mini = llabs(sum);
            left = start;
            right = end;
        }
        if (sum < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << arr[left] << " " << arr[right] << endl;
}