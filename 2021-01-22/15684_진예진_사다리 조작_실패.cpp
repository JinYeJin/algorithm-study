/*
15684 사다리 조작 www.acmicpc.net/problem/15684
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int N, M, H;
int a, b, min_ladder = -1;
bool game[10][30];


bool check_answer(){
    int is_arrive = 0;
    for(int v = 0; v < N; v++){
        int current_v = v;
        for(int h = 0; h < H; h++){
            if(game[h][current_v]) current_v += 1;
            else if(game[h][current_v-1]) current_v -= 1;
        }
        
        if(current_v == v) is_arrive++;
        else return false;
    }

    return true;
}

bool can_ladder(int hori, int verti){
    bool condi1 = game[hori][verti];
    bool condi2 = game[hori][verti-1];
    bool condi3 = game[hori][verti+1];

    if(condi1 || condi2 || condi3) return false;
    else return true;
}

bool boundary(int h, int v){
    return h < H && h >= 0 && v >= 0 && v < N;
}

void set_ladder(int h_idx, int v_idx, int num_ladder){
    if(!boundary(h_idx, v_idx)) return;
    if(num_ladder > 3) return;
    if(check_answer()){
        min_ladder = num_ladder;
        return;
    }

    if(can_ladder(h_idx+1, v_idx)){
        game[h_idx+1][v_idx] = true;
        set_ladder(h_idx+1, v_idx, num_ladder+1);
        game[h_idx+1][v_idx] = false;
    }

    if(can_ladder(h_idx, v_idx+1)){
        game[h_idx][v_idx] = true;
        set_ladder(h_idx, v_idx+1, num_ladder+1);
        game[h_idx][v_idx] = false;
    }

    set_ladder(h_idx+1, v_idx, num_ladder);
    set_ladder(h_idx, v_idx+1, num_ladder);
}

int main(){
    FILE *stream =freopen("S2\\29\\input\\15684.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> H;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        game[a][b] = true;
    }

    set_ladder(0, 0, 0);


    cout << min_ladder;
    return 0;
}
