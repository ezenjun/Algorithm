#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, t, k, start, end;
    int table[1001]={0,}; 
    int sum[1001]={0,};
    cin >> n >> t;
    for(int i=0; i< n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> start >> end;
            for(int p=start; p<end; p++){
                table[p]++;
            }
        }
    }
    sum[0] = table[0];
	for (int i = 1; i <= 1000; i++) {
        sum[i] += sum[i - 1] + table[i];
    }

    int tmp = sum[t - 1];
	start = 0;
	end = t;
	for (int i = 1; i <= 1000 - t; i++) {
		if (sum[i + t - 1] - sum[i - 1] > tmp) {
			start = i;
			end = i + t;
		}
		tmp = max(sum[i + t - 1] - sum[i - 1], tmp);
	}
    
	cout << start << ' ' << end << endl;
}