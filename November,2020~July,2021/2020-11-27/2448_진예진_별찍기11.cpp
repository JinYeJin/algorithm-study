/*
[백준 2448 별 찍기 - 11] acmicpc.net/problem/2448
*/
#include <stdio.h>
#include <iostream> 
#define ABS(a) a > 0 ? a:-a

using namespace std;

bool star[3074][6145];

void print_star(int x, int y, int size){
	if(size == 3){
        for(int r = 0; r < 3; r++){
            for(int c = -2; c <= 2; c++){
                if(r == 0) star[y][x] = true;
                else if((r == 1) && ((c==1) || (c==-1))){
                    star[y+r][x+c] = true;
                }
                else if(r == 2) star[y+r][x+c] = true;
            }
        }
	}
	else{
		size /= 2;
		print_star(x, y, size);
		print_star(x-size, y+ size, size);
		print_star(x+size, y+ size, size);
	}
}

int main(){
    FILE *stream =freopen("S2\\22\\input\\2448.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    print_star(N-1, 0, N);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < 2*N-1; c++){
            if(star[r][c]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
