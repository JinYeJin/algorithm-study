#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> dp;
string code;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>code;
    dp.resize(code.size()+1,0);
    
    int temp;
    dp[0] = 1;
    if(code[0]!='0')
        dp[1] = 1;

    for(int i=2; i<code.size()+1;i++){
        temp = stoi(code.substr(i-2,2));
        if(code[i-1]!='0')
            dp[i]=dp[i-1];
        if(10<=temp and temp<=26)
            dp[i]=(dp[i]+dp[i-2])%1000000;
    }
    cout<<dp[code.size()]<<endl;
    return 0;
}
