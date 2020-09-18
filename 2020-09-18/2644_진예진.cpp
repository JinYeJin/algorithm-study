/*
*/
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

int answer = -1;
int goal;
bool visited[100];
map<int, vector<int>> relation;

void count(int idx, int cnt){
    if(relation[idx].size() == 0 || visited[idx]) return;

    visited[idx] = true;

    for(int i = 0; i < relation[idx].size(); i++){
        if(relation[idx][i] == goal){
            printf("%d", cnt+1);
            exit(0);
        }
        count(relation[idx][i], cnt + 1);
    }
}


int main(){
    FILE *stream =freopen("S2\\15\\input\\2644.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, start, M;

    scanf("%d", &N);
    scanf("%d %d", &start, &goal);
    scanf("%d", &M);

    int tmp_a, tmp_b;

    for(int i = 0; i < M; i++){
        scanf("%d %d", &tmp_a, &tmp_b);
        relation[tmp_a].push_back(tmp_b);
        relation[tmp_b].push_back(tmp_a);
    }

    int p;
    memset(visited, false, sizeof(visited));

    count(start, 0);

    printf("%d", -1);
    return 0;
}
