/*
15863 감시
*/
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <string.h>

using namespace std;


typedef struct Coord{
    Coord(int x, int y, int type, int d, int rotate_available):
        x(x), y(y), d(d), rotate_available(rotate_available){}
    int x, y, type, d, rotate_available;
}Coord;

int N, M, global_blind = 987654321;
int original_office[10][10];
vector<Coord> cctv;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int num_d[] = {1, 2, 2, 3, 4};

int rotate(int d){
    return (d+1) % 4;
}

int flip(int d){
    return (d+2) % 4;
}

int blind_count(int final_office[10][10]){
    int return_value = 0;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(final_office[r][c] == 0){
                return_value++;
            }
        }
    }
    return return_value;
}

void area_check(int temp_office[10][10], Coord c){
    if(c.type == 2){
        for(int i = 0; i < num_d[c.type]; i++){
            if(i == 1) c.d = flip(c.d);
            while(true){
                int nx = dx[c.d];
                int ny = dy[c.d];

                if(temp_office[ny][nx] == -1) break;

                temp_office[ny][nx] = 7;
            }
        }
    }
    else{
        for(int i = 0; i < num_d[c.type]; i++){
            if(i > 1) c.d = rotate(c.d);
            while(true){
                int nx = dx[c.d];
                int ny = dy[c.d];
                if(temp_office[ny][nx] == -1) break;

                temp_office[ny][nx] = 7;
            }
        }
    }
}


void combination(int office[10][10], int index){
    if(index >= cctv.size()){
        int blind = blind_count(office);
        global_blind = global_blind > blind ? blind : global_blind;
        return;
    }

    Coord origin_c = cctv[index];
    Coord *c = &cctv[index];
    int copy_office[10][10];

    copy(&office, &office + 100, copy_office);

    for(int i = 0; i < c->rotate_available; i++){
        c->d = rotate(c->d);
        combination(copy_office, index + 1);
    }
    *c = origin_c;
    copy(&office, &office + 100, copy_office);

    combination(copy_office, index + 1);
}


int main(){
    FILE *stream =freopen("S2\\35\\input\\15683.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(original_office, -1, sizeof(original_office));

    cin >> N >> M;

    for(int r = 0; r < N; r++){
        for(int c =0; c < M; c++){
            cin >> original_office[r][c];
            if(original_office[r][c] != 0){
                if(original_office[r][c] != 6){
                    if(original_office[r][c] == 2)
                        cctv.push_back(Coord(c, r, original_office[r][c], 0, 1));
                    else if(original_office[r][c] == 5)
                        cctv.push_back(Coord(c, r, original_office[r][c], 0, 0));
                    else if(original_office[r][c] == 0)
                        cctv.push_back(Coord(c, r, original_office[r][c], 0, 3));
                    original_office[r][c] = 7; // cctv 있던 자리에 체크
                }
            }
        }
    }


    cout << global_blind;

    return 0;
}
