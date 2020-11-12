/*
2020-06-20 진예진
[백준 16236 아기상어] https://www.acmicpc.net/problem/16236
*/

#include <stdio.h>
#include <queue>
#define my_abs(a) (a > 0 ? a : -a)

using namespace std;

typedef struct Shark{
    Shark(int x, int y, int size): x(x), y(y), size(size){};
    int x, y, size;
}Shark;

typedef struct Fish{
    Fish(int x, int y, int distance): x(x), y(y), size(size), distance(distance){};
    int x, y, size, distance;
}Fish;

int N;
int ocean[20][20];
bool visited[20][20];
// 탐색 우선순위 상, 좌, 우, 하
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
queue<Shark> path;
// 거리가 짧은 순으로 정렬되도록 정의
priority_queue<Fish, vector<Fish>, compare> fishes;

struct compare
{
    // 1. 거리가 짧고 2. 위쪽이고, 3. 왼쪽에 있는 순서
    // 2번째 인자의 우선순위가 높다면 true
    // 거리가 작은 순으로 정렬하려 한다면 a가 큰 것을 리턴
    bool operator()(Fish &a, Fish &b){
        if(a.distance == b.distance){
            if(a.y == b.y){
                return a.x > b.x;
            }
            return a.y > b.y;
        }
        return a.distance > b.distance;
    }
};


int get_distance(Shark shark, Fish fish){
    return my_abs(shark.x - fish.x) + (shark.y - fish.y);
}

bool boundary_check(Shark shark){
    if(shark.x < 0 || shark.x >= N || shark.y < 0 || shark.y >= N) return false;
    else return true;
}

// 상어가 이동 할 때마다 거리를 새로 계산하기 위한 함수
void update_distance(Shark shark, priority_queue<Fish, vector<Fish>, compare> fishes){
    while(!fishes.empty()){
        Fish fish = fishes.top();
        fishes.pop();

        fish.distance = get_distance(shark, fish);

        fishes.push(fish);
    }
}

/*
void can_eat(Shark shark, Fish fish){
    // 상어가 물꼬기 있는 데 까지 왔으면
    if(shark.x == fish.x && shark.y == fish.y){
        // 먹을 수 있는 경우(상어가 더 큼)
        if(shark.size > fish.size)
        // 걍 지나가는 경우(크기가 같은 경우)
        else if(shark.size == fish.size)
        // 먹을 수 없는 경우(상어가 더 작음)
        else
    } 

    Shark new_shark = {shark.x, shark.y, shark.size};

    while(get_distance(new_shark, fish) != 0){
        // x 축 이동
        if(new_shark.x == fish.x);
        else if(new_shark.x > fish.x) new_shark.x--;
        else new_shark.x++;
    }
}
*/

// 네 방향을 균일하게 탐색하기 위해서 BFS
void swim(Shark start){
    path.push(start);
    bool is_fish = false;
    
    while(!path.empty()){
        Shark shark = path.front();
        path.pop();

        for(int i = 0; i < 4; i++){
            Shark new_shark = {shark.x + dx[i], shark.y + dy[i], shark.size};
            bool *visit_check = &visited[shark.x][shark.y];

            if(boundary_check(new_shark) || *visit_check == true) continue;

            int* next = &ocean[new_shark.y][new_shark.x];

            // 물고기가 없으면
            if(next != 0)
        }

    }    


}

int main(){
    FILE *stream = freopen("S2\\4\\input\\16236_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &ocean[i][j]);
            // 상어이면
            if(ocean[i][j] == 9){
                Shark shark = {i, j, 2};
                ocean[i][j] = 0;
            }
            else if(ocean[i][j] == 0) continue;
            else{
                fishes.push(Fish(i, j, ocean[i][j]));
            }
        }
    }

    swim(Shark(0, 0, 2));


    return 0; 
}
