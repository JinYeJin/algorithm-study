#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int aisle[8][8];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool check_answer(int r, int c){
    for(int d = 0; d < 4; d++){
        for(int nr = r; ; nr + dy[d]){
            for(int nc = c; nc + dx[d]){
                if(aisle[nr][nc] == -1) break;
                if(aisle[nr][nc] == 2) return false; // student
            }
        }
    }
    return true;
}

bool set_wall(int num_wall, int r, int c){
    if(aisle[r][c] == -1) return;
    if(num_wall > 3){
        for(int r = 0; r <= N; r++){
            for(int c = 0; c <= N; c++){
                if(aisle[r][c] == 1){ // teacher
                    if(check_answer == false) return false; // NO
                }
            }
        }
        return true; // YES
    }

    // ㅠㅠ
    set_wall()
}


int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;


    for(int r = 0; r <= N; r++){
        for(int c = 0; c <= N; c++){
            if(r == 0 || c == 0 || r == N || c == N)
                aisle[r][c] = -1;
            else{
                char temp;
                cin >> temp;

                switch(temp){
                    case 'X':
                        aisle[r][c] = 0;
                    case 'T':
                        aisle[r][c] = 1;
                    case 'S':
                        aisle[r][c] = 2;
                }
            }
        }
    }

    

    return 0;
}
