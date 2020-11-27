/*
[백준 9466 텀 프로젝트] acmicpc.net/problem/9466
*/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


int students[100002];
int member[100002]; // 사이클에 몇 명이 있는지
bool visited[100002];
int depth;
int cycle;

int find_loop(int number){
    if(visited[number]){ // 루프
        // pivot = number;
        return number;
    }

    visited[number] = true;
    
    int pivot = find_loop(students[number]);
    depth++;

    if(pivot == number){
        member[number] = depth;
        cycle += depth;
        depth = 0;
    }

    return pivot;
}

int main(){
    FILE *stream =freopen("S2\\22\\input\\9466.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;

    cin >> T;

    for(int t = 0; t < T; t++){
        cycle = 0;
        cin >> N;
        memset(visited, false, sizeof(visited));
        
        for(int n = 1; n <= N; n++){
            cin >> students[n];
        }

        for(int n = 1; n <= N; n++){
            depth = 0;
            if(!visited[n]) find_loop(n);
        }

        cout << N - cycle << "\n";

    }

    return 0;
}
