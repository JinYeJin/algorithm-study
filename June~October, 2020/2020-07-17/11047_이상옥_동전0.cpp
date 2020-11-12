#include <iostream>

using namespace std;

int answer=0, money;

void dfs(int n){
    int A;
    cin>>A;
    if(n>1) dfs(n-1);

    if(money>=A){
        answer += money/A;
        money %= A;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n>>money;
    dfs(n);
    cout<<answer<<endl;
    return 0;
}
