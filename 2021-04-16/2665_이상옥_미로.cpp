#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define check(i,j) (0<=i && i<n && 0<=j && j<n)
using namespace std;

int BFS(char** arr, int n){
    int answer=0,di[]={1,-1,0,0}, dj[]={0,0,1,-1};

    bool** visited;
    visited = (bool**)malloc(sizeof(bool*)*n);
    for(int i=0;i<n;i++){
        visited[i]=(bool*)malloc(sizeof(bool)*n);
        memset(visited[i],0,sizeof(bool)*n);
    }
    queue<pair<int,int>> Q,next_Q;
    next_Q.push({0,0});
    visited[0][0]=1;

    while(next_Q.size()){
        swap(Q,next_Q);
        while(Q.size()){
            auto [i,j]=Q.front(); Q.pop();
            if(i==n-1 && j==n-1) return answer;
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(!check(ni,nj) || visited[ni][nj]) continue;
                visited[ni][nj]=1;
                if(arr[ni][nj]=='1'){
                    Q.push({ni,nj});
                }else{
                    next_Q.push({ni,nj});
                }
            }
        }
        answer++;
    }
    return -1;
}

int main()
{
    //15:20 시작 16:00 제출
    int n,answer=0;
    char **arr;
    cin>>n;
    arr = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        arr[i]=(char*)malloc(sizeof(char)*n+1);
    }
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    cout<<BFS(arr, n);
    
    return 0;
}

