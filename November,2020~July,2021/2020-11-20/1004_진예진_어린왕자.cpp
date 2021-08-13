/*
[백준 1004 어린왕자] acmicpc.net/problem/1004
주의 https://www.acmicpc.net/board/view/26374
*/
#include <stdio.h>
#include <iostream> 
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;


typedef struct Coord{
    Coord(int x, int y, int r): x(x), y(y), r(r) {}
    int x, y, r;
}Coord;

bool is_inside(Coord a, Coord circle){
    int distance = (circle.x - a.x) * (circle.x - a.x)
                    + (circle.y - a.y) * (circle.y - a.y);
    if((circle.r*circle.r) > distance) return true; // 원 안에 있음
    else return false;
}

int main(){
   FILE *stream =freopen("S2\\21\\input\\1004.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N;
    int x1, y1, x2, y2, r;

    cin >> T;

    for(int t = 0; t < T; t++){
        int count = 0;
        cin >> x1 >> y1>> x2 >> y2;
        Coord start = {x1, y1, 0};
        Coord end = {x2, y2, 0};

        cin >> N; 

        for(int n = 0; n < N; n++){
            cin >> x1 >> y1>> r;
            Coord planet = {x1, y1, r};
            
            // 둘 중 하나만 참일 때 더해줌 XOR
            if(is_inside(start, planet) ^ is_inside(end, planet)){
                count++;
            }
        }

        cout << count << "\n"; 
    }
    return 0;
}
