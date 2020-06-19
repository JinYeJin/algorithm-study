/*
2020-06-19 진예진
[백준 2617 구슬 찾기] https://www.acmicpc.net/problem/2617
*/
#include <iostream>
#include <vector>
#define MAX_INT 101

using namespace std;


int N, M, a, b;
int cnt, rcnt, result, base_num;
bool check[MAX_INT], rcheck[MAX_INT];

vector<int> v[MAX_INT];// 정방향
vector<int> r[MAX_INT];// 역방향

// 정방향 dfs
void dfs(int node){
    // 방문한 노드를 trure로
    check[node] = true;
    
    for(int i = 0; i < v[node].size(); i++){
        int next = v[node][i];
        // 방문한 적이 없으면 dfs로 들어감
        if(!check[next]){
            // ??
            cnt++;
            dfs(next);
        }
    }
}

// 역방향 dfs
void rdfs(int node){
    rcheck[node] = true;
    
    for(int i=0; i<r[node].size(); i++){
        int next = r[node][i];
        if(!rcheck[next]){
            rcnt++;
            rdfs(next);
        }
    }
}

// 방문 기록 및 방문 개수 초기화
void init(){
    cnt = 0;
    rcnt = 0;
    for(int i = 1; i <= N; i++){
        check[i] = false;
        rcheck[i] = false;
    }
}

int main(){
    
    scanf("%d %d", &N, &M);
    
    // 구슬이 어떻게 연결되어 있는지(엣지) 정보를 입력받는다.
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        // 정방향은 v에 넣는다(무거운거 - > 가벼운거)
        v[a].push_back(b);
        
        // 역방향은 r에 넣는다.(가벼운거 -> 무거운 거) 
        r[b].push_back(a);
    }
    
    // N개 중에서 어디가 중간인지 계산
    base_num = (N+1)/2;

    // 정점마다 DFS 수행
    for(int i=1; i<=N; i++){
        init();
        
        dfs(i);
        rdfs(i);
        
        // base_num 이 중간번호를 저장하고 있음, 중간번호보다 크면 땡
        if(cnt >= base_num || rcnt >= base_num){
            result++;
        }
    }
    
    printf("%d", result);
}
