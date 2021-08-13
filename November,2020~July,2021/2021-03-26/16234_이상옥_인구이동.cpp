#include <iostream>
#include <cstring>
#include <algorithm>

#define check(i,j) (0<=i && i<N && 0<=j && j<N)
using namespace std;

int pnt[2500];
int get_pnt(int a){
    return (pnt[a]==-1?a:get_pnt(pnt[a]));
}
void up_pnt(int a, int b){
    int pa=get_pnt(a),pb=get_pnt(b);
    if(pa!=pb){
        pnt[pb]=pa;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,L,R,A[2500];
    cin>>N>>L>>R;
    for(int i=0;i<N*N;i++){
        cin>>A[i];
    }
    int answer=0;
    for(;answer<2001;answer++){
        int sum[2500]={0},cnt[2500]={0};
        bool flag=false;
        memset(pnt,-1,sizeof(pnt));
        for(int a=0;a<N*N;a++){
            if(a>=N){//위로가짐
                int sub=abs(A[a]-A[a-N]);
                if(L<=sub && sub<=R){
                    flag=true;
                    up_pnt(a,a-N);
                }
            }
            if(a%N>0){//왼쪽으로 가짐
                int sub=abs(A[a]-A[a-1]);
                if(L<=sub && sub<=R){
                    flag=true;
                    up_pnt(a,a-1);
                }
            }
        }
        if(!flag) break;

        for(int a=0;a<N*N;a++){
            int pa=get_pnt(a);
            sum[pa]+=A[a];
            cnt[pa]++;
        }

        for(int a=0;a<N*N;a++){
            int pa=get_pnt(a);
            A[a]=sum[pa]/cnt[pa];
        }
    }
    cout<<answer;
    return 0;
}
