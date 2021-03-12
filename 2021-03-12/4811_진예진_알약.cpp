/*
4811 알약
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

long long dp[33][33];

void dfs(int w, int h){
    if(w <= 0 && h <= 0) return;

    if(dp[w][h] == -1){
        if(dp[w-1][h+1] == -1)
            if(w > 0) dfs(w-1, h+1);
        if(dp[w][h-1] == -1)
            if(h > 0) dfs(w, h-1);
        dp[w][h] = (dp[w-1][h+1] > 0 ? dp[w-1][h+1] : 0)
                    + (dp[w][h-1] > 0 ? dp[w][h-1] : 0);

        // cout << "dp[" << w << "][" << h << "] = " << dp[w][h] << "\n"; 
        // cout << dp[w-1][h+1] << " " << dp[w][h-1] << "\n\n";
    }
    else return;
}

int main(){
    FILE *stream =freopen("S2\\34\\input\\4811.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < 33; i++){
        dp[0][i] = 1;
    }

    dp[0][0] = 1;
    dp[1][0] = 1;

    while(true){
        int input;
        cin >> input;

        if(input == 0) return 0;
        
        dfs(input, 0);

        cout << dp[input][0] << "\n";
    }

    return 0;
}
