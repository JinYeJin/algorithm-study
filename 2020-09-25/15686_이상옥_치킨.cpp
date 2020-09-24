#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int N,M,a;
vector<bool> visited;
vector<vector<int>> C2H;
vector<pair<int,int>> C,H;

int dis(pair<int,int> A, pair<int,int> B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}
int Comb(int n, int m){
    if(m==0){
        int answer=0;
        for(int i=0;i<H.size();i++){
            int mi=INF;
            for(int j=0;j<C.size();j++)
                if(visited[j]) mi=min(mi, C2H[j][i]);
            answer+=mi;
        }
        return answer;
    }
    else{
        int answer=INF;
        for(int i=n+1;i<=C.size()-m;i++){
            visited[i]=1;
            answer=min(answer,Comb(i, m-1));
            visited[i]=0;
        }
        return answer;
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&a);
            if(a==2) C.push_back({i,j});
            else if(a==1) H.push_back({i,j});
        }
    visited.resize(C.size());
    for(auto c:C){
        vector<int> temp;
        for(auto h:H)
            temp.push_back(dis(c,h));
        C2H.push_back(temp);
    }
    printf("%d",Comb(-1,M));
    return 0;
}
