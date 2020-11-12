#include <stdio.h>
#include <vector>

using namespace std;
int docu[9][9], zero=0;
vector<pair<int,int>> points;
bool row_line[9][10], col_line[9][10], sq[9][10];

bool check(int r, int c, int i){
    return !row_line[r][i] && !col_line[c][i] && !sq[(r/3)*3 + c/3][i];
}

bool DFS(int pp){
    if(pp == zero){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                printf("%d ",docu[i][j]);
            printf("\n");}
        return true;
    }
    auto point = points[pp];
    for(int i=1; i<=9; i++)
        if(check(point.first, point.second,i)){
            row_line[point.first][i]=true;
            col_line[point.second][i]=true;
            sq[(point.first/3)*3 + point.second/3][i]=true;
            docu[point.first][point.second] = i;
            if(DFS(pp+1)) return true;
            row_line[point.first][i]=false;
            col_line[point.second][i]=false;
            sq[(point.first/3)*3 + point.second/3][i]=false;
        }
    return false;
}
int main(){
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            scanf("%d",docu[i]+j);
            if(docu[i][j] == 0){
                zero++;
                points.push_back({i,j}); //r, c
            }
        }
    
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            row_line[i][docu[i][j]]=true;
            col_line[i][docu[j][i]]=true;
            sq[(i/3)*3 + j/3][docu[i][j]]=true;
        }
    DFS(0);
    return 0;
}
