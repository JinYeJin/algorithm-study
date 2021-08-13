/*
[백준 2174 로봇 시뮬레이션] acmicpc.net/problem/2174
*/
#include <stdio.h>
#include <iostream> 
#include <map>
#include <vector>

using namespace std;

typedef struct Robot{
    Robot(int x, int y, int d): x(x), y(y), d(d) {}
    int x, y, d;
}Robot;

int A, B;
int robot_map[101][101];

map<char, int> mapping_direction{{'N', 0}, {'W', 1}, {'E', 2}, {'S', 3}};
int rotate_left[] = {1, 3, 0, 2};
int rotate_right[] = {2, 0, 3, 1};
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

bool boundary(Robot a){
    bool result = a.x > 0 && a.x <= A && a.y > 0 && a.y <= B;
    return a.x > 0 && a.x <= A && a.y > 0 && a.y <= B;
}

int main(){
    FILE *stream =freopen("S2\\21\\input\\2174.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    vector<Robot> robots;

    cin >> A >> B;
    cin >> N >> M;

    robots.push_back(Robot(0,0,0)); // 인덱스 맞추기용

    for(int i = 1; i <= N; i++){
        int x, y;
        char d;
        cin >> x >> y >> d;
        robot_map[y][x] = i;

        robots.push_back(Robot(x, y, mapping_direction[d]));
    }

    for(int i = 0; i < M; i++){
        int number, iteration;
        char command;

        cin >> number >> command >> iteration;

        while(iteration--){
            Robot new_robot = robots[number];
            // 이전 로봇이 있던곳 0으로 초기화(자기자신과 부딪칠 때 방지)
            robot_map[new_robot.y][new_robot.x] = 0;

            if(command == 'L'){
                new_robot.d = rotate_left[new_robot.d];
            }else if(command == 'R'){
                new_robot.d = rotate_right[new_robot.d];
            }else if(command == 'F'){
                new_robot.x += dx[new_robot.d];
                new_robot.y += dy[new_robot.d];
            }

            // 맵 밖으로 나가면
            if(!boundary(new_robot)){
                cout << "Robot " << number <<  " crashes into the wall";
                exit(0);
            } 
            
            // 다른 로봇과 충돌하면
            int *is_robot = &robot_map[new_robot.y][new_robot.x];
            if(*is_robot != 0){
                cout << "Robot " << number << " crashes into robot " << *is_robot;
                exit(0);
            }

            // 위 두 경우에 안걸리면 로봇 업데이트
                *is_robot = number;
                robots[number] = new_robot;
            }
        }

    cout << "OK";
    return 0;
}
