#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;
int V,E,a,b,c;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>V>>E;
    int V2V[401][401]={0,};

    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        V2V[a][b]=c-INF;
    }
    
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                V2V[i][j]=min(V2V[i][j],V2V[i][k]+INF+V2V[k][j]);
    int m=0;
    for(int i=1;i<=V;i++) m=min(m,V2V[i][i]);
    cout<<(m?INF+m:-1);
    return 0;
}
