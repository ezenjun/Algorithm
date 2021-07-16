#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int Answer;
int parent[100001];

int Find(int x){
    // Root인 경우 x를 반환
    if(x == parent[x]){
        return x;
    }
    else{
        // 아니면 Root를 찾아감
        int p = Find(parent[x]);
        parent[x] = p;
        return p;
    }

}
void Union(int x, int y){

    x = Find(x);
    y = Find(y);

    if(x!=y){
        parent[y] = x;
    }
}

int main()
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N; cin >> N;
        int d[100001];	
		for(int i=1; i<=N; i++){
    		parent[i] = i;
		}		

        for(int i=1; i<=N; i++){
            cin >> d[i];
        }
		for(int i=1; i<=N; i++){
			if(i + d[i] > N)continue;
			Union(i,i + d[i]);
		}

		set<int> st;

		for(int i=1 ; i<=N; i++){
			parent[i] = Find(i);
			st.insert(parent[i]);
		}
		Answer = st.size();
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}