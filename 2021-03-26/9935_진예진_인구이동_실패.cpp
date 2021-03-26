/*
16234 인구이동
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int N, L, R;
int total_population;
int total_country;
bool visited[102][102];
int country[102][102];

typedef struct Coord{
    Coord(int y, int x): y(y), x(x) {}
    int x, y;
}Coord;

bool is_open(int value){
    return (value >= L) && (value <= R);
}

bool boundary(Coord c){
    return (c.x >= 0) && (c.x < N) && (c.y >= 0) && (c.y < N);
}

int open_country(Coord c){
    for(int d = 0; d < 4; d++){
        Coord n = {c.y + dy[d], c.x + dx[d]};
        bool *visit = &visited[n.y][n.x];

        if(*visit == true) continue;
        if(boundary(n) == false) continue;

        int *next_country = &country[n.y][n.x];
        int diff = abs(country[c.y][c.x] - *next_country);
        if(is_open(diff)){
            total_country += 1;
            total_population += *next_country;
            *visit = true;
            open_country(n);
        }
    }

    if(total_country > 1){
        int avg_population = total_population / total_country;
        // cout << "avg: " << avg_population << "\n";
        country[c.y][c.x] = avg_population;
        return true;
    }
    return false;
}

void print_arr(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cout << country[r][c];
            cout << " ";
        }
        cout << "\n";
    }
}

void print_visit(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cout << visited[r][c];
            cout << " ";
        }
        cout << "\n";
    }
}



int main(){
    // FILE *stream =freopen("S2\\36\\input\\16234.txt", "r", stdin);
    FILE *stream = freopen("C:\\Users\\yeen0\\Documents\\github\\algorithm\\S2\\36\\input\\16234.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> L >> R;

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cin >> country[r][c];
        }
    }

    int total_move = 0;

    // print_arr();
    // cout <<"\n";

    for(int i = 0; i < 2000; i++){
        memset(visited, false, sizeof(visited));
        bool is_moved = false;
        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                if(!visited[r][c]){
                    int temp_moved = false;
                    total_population = country[r][c];
                    total_country = 1;
                    visited[r][c] = true;
                    Coord current = { r, c };

                    temp_moved = open_country(current);

                    if(is_moved == false){
                        if(temp_moved == true) is_moved = true;
                    }


                    // cout << total_move << "\n";
                    // print_arr();
                    // print_visit();
                    // cout << "\n";
                }
            }
        }
        if(is_moved) total_move++;
    }



    cout << "last" << "\n";
    print_arr();
    cout << "\n";

    cout << total_move;
    return 0;
}
