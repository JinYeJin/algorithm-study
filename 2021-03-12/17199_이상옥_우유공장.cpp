#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int,int> conveyor[101];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=1;i<N;i++){
        cin>>conveyor[i].first>>conveyor[i].second;
    }
    for(int s=1;s<=N;s++){
        bool station[101]={0};
        int cnt=1;
        station[s]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<N;j++){
                int a=conveyor[j].first, b=conveyor[j].second;
                if(station[b]==1){
                    if(station[a]!=1){
                        cnt++;
                        station[a]=1;
                    }
                }
            }
        }
        if(cnt==N){
            cout<<s;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
