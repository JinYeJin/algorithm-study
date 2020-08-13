#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[4001][4001];
int main(void){
    string str1;
    string str2;
    
    cin >> str1 >> str2;
    
    int max_index = max(str1.size(),str2.size());
    int min_index = min(str1.size(),str2.size());
    
    if(str1[0] == str2[0]) dp[0][0] = 1;
    if(str1[1] == str2[0]) dp[1][0] = 1;
    if(str1[0] == str2[1]) dp[0][1] = 1;
    
    for(int i=1; i < min_index; i++){
        for(int j=1; j < max_index; j++){
            if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1]+1;
        }
    }
    
    int ans = 0;
    for(int i=0; i < min_index; i++){
        for(int j=0; j < max_index; j++){
            if(ans < dp[i][j]) ans = dp[i][j];
        }
    }
    
    cout << ans << "\n";
    return 0;
}

