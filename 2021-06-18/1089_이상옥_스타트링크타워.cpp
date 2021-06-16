#include "bits/stdc++.h"

using namespace std;

int num[10]={0b111101101101111,0b001001001001001,0b111001111100111,0b111001111001111,0b101101111001001,0b111100111001111,0b111100111101111,0b111001001001001,0b111101111101111,0b111101111001111},N;
double answer=0;
vector<int> permu[9];

vector<int> check(int bit){
    vector<int> nums;
    for(int i=0;i<10;i++){
        if(bit==(bit&num[i])) nums.push_back(i);
    }
    return nums;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string S[5];
    cin>>N;
    for(int i=0;i<5;i++) cin>>S[i];
    
    for(int i=0;i<N;i++){
        int bit=0,level=1<<14;
        for(int r=0;r<5;r++){
            for(int c=i*4;c<i*4+3;c++){
                if(S[r][c]=='#'){
                    bit+=level;
                }
                level/=2;
            }
        }
        auto temp=check(bit);
        if(temp.empty()){
            cout<<-1;
            return 0;
        }
        permu[i]=temp;
    }
    int cnt=1,mul=1;
    for(int i=N-1;i>=0;i--){
        double sum=0;
        for(int p : permu[i]){
            sum+=p;
        }
        answer+=sum/permu[i].size() * mul;
        mul*=10;
    }
    cout<<answer;
    return 0;
}


