#include <iostream>
#include <algorithm>

using namespace std;

int A[50][50];
void rotation(int x1, int y1, int x2, int y2){
    int temp=A[x1][y1];
    for(int j=y1+1;j<=y2;j++){
        swap(A[x1][j],temp);
    }
    for(int i=x1+1;i<=x2;i++){
        swap(A[i][y2],temp);
    }
    for(int j=y2-1;j>=y1;j--){
        swap(A[x2][j],temp);
    }
    for(int i=x2-1;i>=x1;i--){
        swap(A[i][y1],temp);
    }
}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,M,K,r[6],c[6],s[6],arr[50][50];
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<K;i++){
        cin>>r[i]>>c[i]>>s[i];
    }
    int permu[]={0,1,2,3,4,5},answer=1e9;
    do{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                A[i][j]=arr[i][j];
            }
        }//hard_capy

        for(int i=0;i<K;i++){
            int idx=permu[i];
            for(int j=1;j<=s[idx];j++){
                rotation(r[idx]-j-1, c[idx]-j-1, r[idx]+j-1, c[idx]+j-1);
            }
        }

        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=0;j<M;j++){
                sum+=A[i][j];
            }
            answer=min(answer,sum);
        }
    }while(next_permutation(permu,permu+K));
    cout<<answer;
    return 0;
}


