#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define check(x,y) (0<x && x<=N && 0<y && y<=N)
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int N,M,K,land[11][11],S2D2[11][11],x,y,z,dx[]={1,1,1,-1,-1,-1,0,0},dy[]={1,-1,0,1,-1,0,1,-1};

    deque<pair<pair<int,int>,int>> trees;
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>S2D2[i][j];
            land[i][j]=5;
        }
    }
    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        trees.push_back({{x,y},z});
    }
    sort(trees.begin(),trees.end());
    for(int i=0;i<K;i++){
        deque<pair<pair<int,int>,int>> new_trees;
        vector<pair<pair<int,int>,int>> dead_trees;
        while(trees.size()){
            auto tree=trees.front(); trees.pop_front();
            x=tree.first.first, y= tree.first.second, z=tree.second;
            //봄
            if(land[y][x]>=z){
                land[y][x]-=z;
                z++;
                new_trees.push_back({{x,y},z});
                //가을,번식
                if(z%5==0){
                    for(int d=0;d<8;d++){
                        int nx=x+dx[d], ny=y+dy[d];
                        if(check(nx,ny)){
                            new_trees.push_front({{nx,ny},1});
                        }
                    }
                }
            }//여름
            else if(z>1){
                dead_trees.push_back({{x,y},z/2});
            }
        }
        
        //가을
        for(auto tree: dead_trees){
            x=tree.first.first, y= tree.first.second, z=tree.second;
            land[y][x]+=z;
        }
        //겨울
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                land[i][j]+=S2D2[i][j];
            }
        }
        swap(trees,new_trees);
    }
    cout<<trees.size();
    return 0;
}
