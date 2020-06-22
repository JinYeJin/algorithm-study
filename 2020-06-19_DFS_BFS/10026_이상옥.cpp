#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> drawing;

void same_color(char color, int i, int j){
    if(i-1>=0 and color == drawing[i-1][j]){
        drawing[i-1][j] = '0';
        same_color(color,  i-1, j);
    }
    if(i+1<N and color == drawing[i+1][j]){
        drawing[i+1][j] = '0';
        same_color(color,  i+1, j);
    }
    if(j-1>=0 and color == drawing[i][j-1]){
        drawing[i][j-1] = '0';
        same_color(color, i, j-1);
    }
    if(j+1<N and color == drawing[i][j+1]){
        drawing[i][j+1] = '0';
        same_color(color, i, j+1);
    }
}

int main(int argc, const char * argv[]){
    int answer1=0, answer2=0;

    vector<vector<char>> drawing_n;
    vector<vector<char>> drawing_c;
    
    cin>>N;
    drawing_c.resize(N,vector<char>(N,'0'));
    drawing_n.resize(N,vector<char>(N,'0'));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>drawing_c[i][j];
            if(drawing_c[i][j] == 'G') drawing_n[i][j] = 'R';
            else drawing_n[i][j] = drawing_c[i][j];
        }
    }
    drawing = drawing_c;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(drawing[i][j] != '0'){
                answer1++;
                drawing[i][j] = '0';
                same_color(drawing_c[i][j],i,j);
            }
        }
    }
    drawing = drawing_n;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(drawing[i][j] != '0'){
                answer2++;
                drawing[i][j] = '0';
                same_color(drawing_n[i][j],i,j);
            }
        }
    }
    
    cout<<answer1<<' '<<answer2<<endl;
    return 0;
}
