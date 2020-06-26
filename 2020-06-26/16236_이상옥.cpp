#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> foods;
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};
int size = 2;
int grow = 0;
int Call_Mom = 0;

bool check(vector<int> point){
    return point[0] >= 0 and point[1] >=0 and point[0] < N and point[1] < N and foods[point[0]][point[1]] <= size;
}
vector<int> Point(int x, int y){
    vector<int> temp(2,x);
    temp[1]=y;
    return temp;
}
vector<int> find_food(vector<int> baby){
    vector<vector<bool>> visited(N, vector<bool>(N,false));
    vector<vector<int>> move;
    int cnt = 0;
    move.push_back(baby);
    visited[baby[0]][baby[1]]=true;
    while(1){
        vector<vector<int>> next_move;
        for(auto p:move){
            if(0 < foods[p[0]][p[1]] and foods[p[0]][p[1]] < size){
                Call_Mom+=cnt;
                return p;
            }
            for(int x=0; x<4; x++){
                vector<int> next = Point(p[0] + di[x], p[1] + dj[x]);
                if(check(next) and !visited[next[0]][next[1]]){
                    visited[next[0]][next[1]] = true;
                    next_move.push_back(next);
                }
            }
        }
        if(next_move.empty()) return Point(-1,-1);
        sort(next_move.begin(), next_move.end());
        move = next_move;
        cnt++;
    }
   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<int> baby;
    cin>>N;
    foods.assign(N, vector<int>(N,0));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>foods[i][j];
            if(foods[i][j] == 9){
                baby = Point(i,j);
            }
        }
    }
    while(1){
        vector<int> next = find_food(baby);
        if(next[0] == -1) break;
        
        foods[baby[0]][baby[1]] = 0;
        foods[next[0]][next[1]] = 0;
        grow++;

        if(size == grow){
            size++;
            grow=0;
        }
        baby=next;
    }
    cout<<Call_Mom<<endl;
    return 0;
}
