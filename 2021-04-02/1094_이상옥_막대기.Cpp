#include <iostream>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,answer=0;
    cin>>N;
    for(;N;N/=2){
        if(N%2){
            answer++;
        }
    }
    cout<<answer;
    return 0;
}
