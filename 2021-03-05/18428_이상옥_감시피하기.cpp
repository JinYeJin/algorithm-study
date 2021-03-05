#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char board[6][6];
int N;
vector<pair<int,int>> teachers;

bool detect_student(){
    for(auto teacher : teachers){
        int i=teacher.first,j=teacher.second;
    
        for(int ni=i;ni>=0;ni--){
            if(board[ni][j]=='O'){
                break;
            }
            if(board[ni][j]=='S'){
                return true;
            }
        }
        for(int ni=i;ni<N;ni++){
            if(board[ni][j]=='O'){
                break;
            }
            if(board[ni][j]=='S'){
                return true;
            }
        }
        for(int nj=j;nj>=0;nj--){
            if(board[i][nj]=='O'){
                break;
            }
            if(board[i][nj]=='S'){
                return true;
            }
        }
        for(int nj=j;nj<N;nj++){
            if(board[i][nj]=='O'){
                break;
            }
            if(board[i][nj]=='S'){
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]=='T'){
                teachers.push_back({i,j});
            }
        }
    }
    for(int o1=0;o1<N*N;o1++){
        int i1=o1/N, j1=o1%N;
        if(board[i1][j1]!='X') continue;
        board[i1][j1]='O';
        for(int o2=o1+1;o2<N*N;o2++){
            int i2=o2/N, j2=o2%N;
            if(board[i2][j2]!='X') continue;
            board[i2][j2]='O';
            for(int o3=o2+1;o3<N*N;o3++){
                int i3=o3/N, j3=o3%N;
                if(board[i3][j3]!='X') continue;
                board[i3][j3]='O';
                if(!detect_student()){
                    cout<<"YES";
                    return 0;
                }
                board[i3][j3]='X';
            }
            board[i2][j2]='X';
        }
        board[i1][j1]='X';
    }
    cout<<"NO";
    return 0;
}
