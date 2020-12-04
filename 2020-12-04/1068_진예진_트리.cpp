/*
[백준 1068] https://www.acmicpc.net/problem/11055
틀린 케이스 https://www.acmicpc.net/board/view/59793
https://www.acmicpc.net/board/view/51552
*/
#include <stdio.h>
#include <iostream> 
#include <map>
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\1068.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, temp, remove, answer = 0;
    multimap<int, int> tree;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        tree.insert(pair<int, int>(temp, i));
    }

    cin >> remove;

    queue<int> q;
    q.push(-1);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        auto found = tree.find(parent);

        // 리프노드가 사라지는 경우 예외처리 해줘야 함. 어캐해
        if(found == tree.end()) answer++; // 키 찾았는데 없으면 리프
        else if(found->first == remove) continue; // 지우는 노드면 패스
        else{ // 지워야하는 노드가 아니면
            // 같은 부모인 자식을 모두 큐에 넣음
            for(found; found->first == parent; found++){
                if(found->second == remove) continue;
                q.push(found->second);
            }
        }
    }

    cout << answer;
    return 0;
}
