#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <sstream>
#include <bitset>

using namespace std;

bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i] & now) == vec[i])return false;  // 비트 계산이
    return true;
}

int solution(vector<vector<string>> relation) {
    
    vector<int> answer;
    int row = relation.size();
    int col = relation[0].size();
        
    for(int i=1; i < (1 << col); i++){ // 전체 순회
        set<string> s;
        for(int r=0; r < row; r++){
            string temp = "";
            for(int c=0; c < col; c++){
                if(i&(1 << c)){
                    temp += relation[r][c];
                }
            }
            s.insert(temp);
        }
        if(s.size() == row){
            if(possi(answer, i)){
                answer.push_back(i);
            }
        }
    }
    return answer.size();
}
