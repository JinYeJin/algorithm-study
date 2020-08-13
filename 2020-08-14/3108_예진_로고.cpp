/*
[백준 3108 로고] https://www.acmicpc.net/problem/3108
참고 https://m.blog.naver.com/pjh980918/221819675526
     https://yabmoons.tistory.com/179
*/
#include <stdio.h>
#include <queue>
#define OFFSET 500

using namespace std;

typedef struct Turtle{
    Turtle(int x, int y): x(x), y(y) {}
    int x, y;
}Turtle;

typedef struct Rectangle{
    Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
    int x1, y1, x2, y2;
    void add_all(int value){
        x1 += value;
        y1 += value;
        x2 += value;
        y2 += value;
    }
    void multiply_all(int value){
        x1 *= value;
        y1 *= value;
        x2 *= value;
        y2 *= value;
    }
}Rectangle;

int N, group_num;
// 북, 동, 남, 서
Turtle dxdy[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int map[2001][2001];

// map에 1로 사각형을 그린다.
void draw_rectangle(Rectangle r) {
	for (int i = r.x1; i <= r.x2; i++) {
		map[r.y1][i] = 1;
		map[r.y2][i] = 1;
	}

	for (int i = r.y1; i <= r.y2; i++) {
		map[i][r.x1] = 1;
		map[i][r.x2] = 1;
	}
}

bool boundary_check(Turtle t){
    return t.x >= 0 && t.x < 2001 && t.y >= 0 && t.y < 2001;
}


// dfs로 모두 그리기
void draw_all(Turtle t){
    	map[t.y][t.x] = 2; // 방문했다.

	for (int i = 0; i < 4; i++)
	{
		Turtle nt = { t.x + dxdy[i].x, t.y + dxdy[i].y };

		if(!boundary_check(nt)) continue;

        // 0: 빈 곳, 2: 이미지난 곳
		if (map[nt.y][nt.x] == 0 || map[nt.y][nt.x] == 2) continue;

		draw_all(nt);
	}
}

void draw_rec(queue<Turtle> points) {
	while (!points.empty()) {
        Turtle t = points.front();
		points.pop();

        // 0: 사각형 선이 없음, 2: 이미 방문했던 곳임
		if (map[t.y][t.x] == 0 || map[t.y][t.x] == 2) continue;

        group_num++;
        // 현재 찾은 사각형 지점에서 이어지는 선들을 전부 잇는다
        draw_all(t);
	}
}


int main(){
    FILE *stream =freopen("S2\\11\\input\\3108.txt", "r", stdin);
    if(!stream) perror("freopen");

    queue<Turtle> points;

    scanf("%d", &N);
    points.push(Turtle(0, 0)); // 0, 0을 시작으로 잡음

	for (int i = 0; i < N; i++) {
        Rectangle in = { 0, 0, 0, 0 };

        scanf("%d %d %d %d", &in.x1, &in.y1, &in.x2, &in.y2);

        in.add_all(OFFSET);
        in.multiply_all(2);

        points.push(Turtle(in.x1, in.y1));
        draw_rectangle(in);
	}

	draw_rec(points);
	
	if (map[1000][1000] == 2) // 원점에서는 그리면서 시작하므로 원점부터 그리는 경우에서는 1번을 빼줘야한다.
		group_num--;

    /*
    for(int i = 1000; i < 1020; i++){
        for(int j = 1000; j < 1020; j++){
            if(map[j][i] == 1) printf("1");
            else if(map[j][i] == 2) printf("2");
            else printf(" ");
        }
        printf("\n");
    }
    */
    printf("%d", group_num);

    return 0;
}
