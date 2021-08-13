#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int N,K,ne;
    deque<int> A;
    cin>>N>>K;
    deque<bool> robot(N,0);
    
    for(int i=0;i<2*N;i++){
        cin>>ne;
        A.push_back(ne);
    }//1 2 ... 2N -> pop_back -> push_front
    int cnt=0;
    while(++cnt){
        A.push_front(A.back());A.pop_back();//컨베이어 벨트 회전
        robot.push_front(0);robot.pop_back();//컨베이어 벨트 위에있는 로봇도 같이 회전!
        
        robot.back()=0;
        for(int i=N-2;i>=0;i--){//로봇이 움직여서 다음칸으로 이동
            if(robot[i]==1 && robot[i+1]==0 && A[i+1]>0){
                swap(robot[i],robot[i+1]);
                if(--A[i+1]==0){
                    if(--K==0){
                        cout<<cnt;
                        return 0;
                    }
                }
            }
        }
        if(A.front()>0){//올리는 칸이 0보다 크면 로봇을 올리다.
            robot.front()=1;
            if(--A.front()==0){
                if(--K==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}


