#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool update=true;
#define NO_ROOT 10000000

int min(int a, int b){
    if(a>b){
        update = true;
        return b;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int i,j,r;
    cin>>N>>M;
    
    vector<vector<int>> bus_root(N,vector<int>(N,NO_ROOT));
    
    for(int x =0; x<M; x++){
        cin>>i>>j>>r;
        bus_root[i-1][j-1]=min(bus_root[i-1][j-1],r);
    }
    while(update){
        update=false;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++)
                    if(i!=j and j!=k and k!=i)
                        bus_root[i][j]=min(bus_root[i][j],bus_root[i][k]+bus_root[k][j]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<< bus_root[i][j]%NO_ROOT<<' ';
        cout<<endl;
    }
    
    return 0;
}
