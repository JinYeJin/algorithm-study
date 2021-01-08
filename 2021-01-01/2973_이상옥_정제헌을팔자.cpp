#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,answer;
    char a;
    while(1){
        cin>>a;
        if(cin.eof()) break;
        cin>>a>>N;
        answer=1;
        for(int i=N+1;i<N*2;i++){
            answer+=((i*N)%(i-N)==0);
        }
        cout<<answer<<'\n';
    }
    return 0;
}
