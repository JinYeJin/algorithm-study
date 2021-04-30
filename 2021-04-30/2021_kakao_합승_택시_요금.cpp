#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 99999999

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    int weight[202][202];
    
    for(int i = 1; i <= n; i++){
        weight[i][i] = 0;
    }
    for(int i = 0; i < 202; i++){
        for(int j = 0; j < 202; j++){
            if(i == j) weight[i][j] = 0;
            else weight[i][j] = INF;
        }
    }
    
    for(int i = 0; i < fares.size(); i++){
        int c = fares[i][0];
        int d = fares[i][1];
        
        weight[c][d] = fares[i][2];
        weight[d][c] = fares[i][2];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                weight[j][k] = min(weight[j][k], weight[j][i] + weight[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        answer = min(answer, weight[s][i] + weight[i][a] + weight[i][b]);
    }
    
    return answer;
}
