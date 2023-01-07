#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(int alp, int cop, int alp_req, int cop_req){
    if(alp >= alp_req && cop >= cop_req)
        return true;
    else
        return false;
}


int main() {
    int alp, int cop;
    vector<vector<int>> problems;
    alp = 10;
    cop = 10;
    problems.push_back({10,15,2,1,2});
    problems.push_back({20,20,3,3,4});

    int answer = 0;
    int solve = 0;
    for(int i=0; i<problems.size(); i++){
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        int alp_rwd = problems[i][2];
        int cop_rwd = problems[i][3];
        int cost = problems[i][4];

        //문제 풀 수 있을 때
        if(check(alp, cop,alp_req,cop_req)){
            alp += alp_rwd;
            cop += cop_rwd;
            solve++;
            if(solve == problems.size())
                break;
            answer += cost;
            continue;
        }
        //문제를 풀 수 없을 때
        else{
            int study = 0, solve = 0;
            int alp_tmp = alp;
            int cop_tmp = cop;
            //공부
            while(alp_tmp < alp_req || cop_tmp < cop_req){
                if(alp_tmp < alp_req){
                    alp_tmp++;
                    study++;
                }
                if(cop_tmp < cop_req){
                    cop_tmp++;
                    study++;
                }
            }
            alp_tmp = alp;
            cop_tmp = cop;
            //이전문제 푼다
            while(alp_tmp < alp_req || cop < cop_req){
                alp_tmp += problems[i-1][2];
                cop_tmp += problems[i-1][3];
                solve += problems[i-1][4];
            }

            if(study>solve){//문제푸는게 이득
                alp += problems[i-1][2]*solve;
                cop += problems[i-1][3]*solve;
                answer += problems[i-1][4]*solve;
            }
            else{//공부하는게 이득
                while(alp < alp_req || cop < cop_req){
                    if(alp < alp_req){
                        alp++;
                        answer++;
                    }
                    if(cop < cop_req){
                        cop++;
                        answer++;
                    }
                }
            }
                
        }
    }
    cout << answer << endl;
}