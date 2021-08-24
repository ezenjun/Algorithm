#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> map;
    set<string> s(gems.begin(), gems.end());
    int start = 0, end = 0;
    for(int i = 0; i<gems.size(); i++){
        string tmp = gems[i];
        map[tmp]++;
        if(map.size() == s.size()) break;
        end++;
    }
    answer[0] = start + 1;
    answer[1] = end + 1;
    int min = end - start;
    while(end < gems.size()){
        string k = gems[start];
        map[k]--;
        start++;
        if(map[k] == 0){
            end++;
            for(; end<gems.size(); end++){
                map[gems[end]]++;
                if(k==gems[end]){
                    break;
                }
            }
            if(end == gems.size())
                break;
        }
        if(min > end - start){
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }
    return answer;
}

int main(){
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems);
}