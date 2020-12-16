#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int N,M,dist[500][500],A,B,C;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>dist[i][j];
        }
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(M--){
        cin>>A>>B>>C;
        cout<<(dist[A-1][B-1]>C?"Stay here\n":"Enjoy other party\n");
    }
    return 0;
}
