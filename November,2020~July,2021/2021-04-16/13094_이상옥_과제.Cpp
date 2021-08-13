#include <iostream>
#include <algorithm>
#include <queue>

#define check(i,j) (0<=i && i<n && 0<=j && j<n)
using namespace std;

pair<int,int> work[1001];
int N;

int main()
{
    //16:00 시작 19:00 끝
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>work[i].first>>work[i].second;
    }
    sort(work,work+N,greater<pair<int,int>>());
    work[N]={0,0};
    
    int gap,i=0,time=1e9,answer=0;
    priority_queue<int> H;
    while(i<=N){
        while(i<=N && work[i].first==time){
            H.push(work[i].second);
            i++;
        }
        gap=time-work[i].first;
        time=work[i].first;
        while(H.size()&& gap--){
            answer+=H.top();H.pop();
        }
    }
    cout<<answer;
    return 0;
}

