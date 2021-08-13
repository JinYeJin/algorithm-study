#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<pair<int,int>> station;
    priority_queue<int> passed_station;
    int N,a,b,s=0,e,fual;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        station.push({-a,b});
    }
    int answer=0;
    cin>>e>>fual;
    while(s<e){
        s+=fual;fual=0;
        while(station.size() && -station.top().first<=s){
            passed_station.push(station.top().second);station.pop();
        }
        if(s<e){
            if(passed_station.empty()){
                cout<<-1;
                return 0;
            }
            fual+=passed_station.top();passed_station.pop();
            answer++;
        }
    }
    cout<<answer;
    return 0;
}


