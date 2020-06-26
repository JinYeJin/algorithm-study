/*
 2020-06-23 진예진
 [백준 17642 연구소 3] https://www.acmicpc.net/problem/17142
 */
#include <stdio.h>
#include <stack>
#include <queue>
#include <string.h>
#define A_VIRUS 0 // active_virus
#define I_VIRUS -3 // inactive_virus
#define WALL -1
#define EMPTY -2


using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y){}
    int x, y;
}Coord;

int N, M, least_time;
bool is_infected;
int lab[50][50];
bool bfs_visited[50][50];
// 상 우 하 좌
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<Coord> viruses, picked;
queue<Coord> spreading;

bool boundary_check(Coord cell){
    return cell.x >= 0 && cell.x < N && cell.y >= 0 && cell.y < N;
}

// 바이러스 퍼뜨리는 bfs
void spread_virus(int infected_lab[][50]){
    while(!spreading.empty()){
        Coord current = spreading.front();
        spreading.pop();
        
        // 상 우 하 좌 4방향 탐색
        for(int i = 0; i < 4; i++){
            Coord next = {current.x + dx[i], current.y + dy[i]};

            bool *visit_check = &bfs_visited[next.y][next.x];
            int *current_cell = &infected_lab[current.y][current.x];
            int *next_cell = &infected_lab[next.y][next.x];

            if(boundary_check(next) == false
               || *visit_check == true
               // 벽이면 못지나감
               || *next_cell == 1) continue;

            //비활성 바이러스
            else if(*next_cell == I_VIRUS){
                *next_cell = *current_cell + 1;
                *visit_check = true;
                spreading.push(next);
            }

            // 빈칸
            else if(*next_cell == EMPTY){
                // 바이러스 감염시키거
                *next_cell = *current_cell + 1;
                *visit_check = true;
                spreading.push(next);
            }
        }
    }

    is_infected = true;
    int max_time = 0;

    // 제일 오래 걸린 시간 찾기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // printf("%d ", infected_lab[i][j]);
            // 하나라도 감염되지 않으면 break 실패
            if(infected_lab[i][j] == EMPTY){
                is_infected = false;
                break;
            }
            else{
                // 1번 테케에서 구석의 5까지 계산방지
                if(lab[i][j] != I_VIRUS) 
                    max_time = infected_lab[i][j] > max_time ? infected_lab[i][j] : max_time;
            }
        }
        if(!is_infected) break;
        // printf("\n");
    }
    if(is_infected) least_time = max_time < least_time? max_time : least_time;
}

// 바이러스 선택은 dfs
void activate_virus(int index){
    // M개 만큼의 바이러스를 활성화하고 바이러스를 퍼트리
    if(index > viruses.size()) return;
    if(M == picked.size()){
        int temp_lab[50][50];

        // 초기화
        while(!spreading.empty()) spreading.pop();
        memcpy(temp_lab, lab, sizeof(temp_lab));
        memset(bfs_visited, false, sizeof(bfs_visited));

        for(int i = 0; i < picked.size(); i++){
            spreading.push(picked[i]);
            bfs_visited[picked[i].y][picked[i].x] = true;
            // 활성 바이러스로 변경
            temp_lab[picked[i].y][picked[i].x] = A_VIRUS;
        }
        spread_virus(temp_lab);
        // printf("\n");
        return;
    }


    // 선택 하는 경우
    picked.push_back(viruses[index]);
    activate_virus(index + 1);
    picked.pop_back();

    // 선택 안하는 경우, 인덱스만 늘려줌
    activate_virus(index + 1);
}

int main(){
    FILE *stream = freopen("S2\\4\\input\\17142_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    // N: 연구소의 크기, M: 놓을 수 있는 바이러스의 개수
    scanf("%d %d", &N, &M);

    // init
    viruses.clear();
    picked.clear();
    least_time = 987654321;
    int empty_count = 0;

    // input => 0: 빈칸, 1: 벽, 2: 바이러스
    // 조정 => -3: 비활성 바이러스, -2: 빈칸, -1: 벽, 0: 활성 바이러스
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &lab[i][j]);
            if(lab[i][j] == 0){
                lab[i][j] = EMPTY;
                empty_count++;
            }
            else if(lab[i][j] == 1) lab[i][j] = WALL;
            // 2 는 비활성 바이러스
            else if(lab[i][j] == 2){
                lab[i][j] = I_VIRUS;
                // 바이러스 선택을 위해서 벡터에 넣음
                viruses.push_back(Coord(j, i));
            }
        }
    }

    // 바이러스는 무조건 1개부터 시작
    // 따라서 빈 공간이 하나도 없으면 바이러스가 다 퍼진 상태
    if(empty_count == 0){
        printf("0");
        return 0;
    }

    activate_virus(0);
    
    if(least_time == 987654321) printf("-1");
    else printf("%d", least_time);

    return 0;
}
