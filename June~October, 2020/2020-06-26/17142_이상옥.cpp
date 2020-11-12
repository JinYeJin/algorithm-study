#include <iostream>
#include <vector>

using namespace std;
int N,M,zero=0,cnt,answer = 1000000;
int di[]={-1,1,0,0}, dj[]={0,0,-1,1}; //상하좌우
vector<vector<int>> active_birus;
vector<vector<int>> lab;


vector<int> Point(int x, int y){
    vector<int> temp(2,x);
    temp[1]=y;
    return temp;
}
bool check(vector<int> point){
    int i=point[0], j=point[1];
    return (0<=i and i<N and 0<=j and j<N) and (lab[i][j]==0 or lab[i][j]==2);
}
bool infection(){
    vector<vector<int>> point(M);
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    
    copy(active_birus.begin(),active_birus.end(), point.begin());
    int infested_zero = 0;
    cnt = 0;
    
    for(auto p : point) visited[p[0]][p[1]] = true;
    while(1){
        if(infested_zero == zero) return true;
        vector<vector<int>> next_point;
        for(auto p:point){
            for(int d=0; d<4; d++){
                vector<int> next=Point(p[0]+di[d], p[1]+dj[d]);
                if(check(next) and !visited[next[0]][next[1]]){
                    visited[next[0]][next[1]] = true;
                    next_point.push_back(next);
                    if(lab[next[0]][next[1]] == 0) infested_zero++;
                }
            }
        }
        cnt++;
        if(next_point.empty()) return infested_zero==zero;
        point = next_point;
    }
}
void active(int M, int pre_i, int pre_j){
    for(int i=pre_i; i<N; i++)
        for(int j=0; j<N; j++){
            if(!(i==pre_i and j<=pre_j) and lab[i][j] == 2){
                active_birus[M] = Point(i,j);
                if(M>0)
                    active(M-1,i,j);
                else{
                    if(infection())
                        answer = min(answer, cnt+1);
                }
            }
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;

    lab.assign(N,vector<int>(N,0));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin>>lab[i][j];
            if(lab[i][j] == 0) zero++;
        }

    active_birus.resize(M);
    active(M-1,0,-1);
    
    cout<<(answer%1000000-1)<<endl;
    return 0;
}

