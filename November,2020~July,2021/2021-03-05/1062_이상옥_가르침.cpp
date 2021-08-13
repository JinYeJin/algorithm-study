#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
string s;
vector<int> s_bits;
int N,K,answer=0;

void DFS(int k, int bit,int s){
    if(k==0){
        int cnt=0;
        for(int i=0;i<N;i++){
            if((bit & s_bits[i])==s_bits[i]){
                cnt++;
            }
        }
        answer=max(answer,cnt);
    }
    for(int i=s;i<26;i++){
        if((bit>>i)%2==0){
            DFS(k-1,bit+(1<<i),i+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    if(K<5){
        cout<<0;
        return 0;
    }
    for(int i=0;i<N;i++){
        int s_bit=0;
        cin>>s;
        for(char c:s){
            s_bit |= 1<<(c-'a');
        }
        s_bits.push_back(s_bit);
    }
    DFS(K-5,532741,1);
    cout<<answer;
    return 0;
}
