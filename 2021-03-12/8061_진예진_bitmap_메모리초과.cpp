/*
8061 Bitmap
*/
#include <stdio.h>
#include <iostream> 
#include <string.h>
#include <queue>
#include <utility>

using namespace std;


int main(){
    FILE *stream =freopen("S2\\34\\input\\8061.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, M;
    int bitmap[184][184];
    int answer[184][184];
    bool visited[184][184];

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    memset(bitmap, -1, sizeof(bitmap));
    memset(answer, -1, sizeof(answer));

    // cin >> N >> M;
    scanf("%d %d", &N, &M);

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            int temp;
            // cin >> bitmap[r][c];
            scanf("%1d", &temp);
            bitmap[r][c] = temp;
        }
        // printf("\n");
    }
    
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            memset(visited, false, sizeof(visited));
            queue<pair<int, int>> path;

            pair<int, int> start = {r, c};

            path.push(start);

            while(!path.empty()){
                auto c = path.front();
                path.pop();

                if(bitmap[c.first][c.second] == 1){
                    int distance = abs(c.first - start.first)
                                    + abs(c.second - start.second);
                    answer[start.first][start.second] = distance;
                    break;
                }

                for(int d = 0; d < 4; d++){
                    pair<int, int> n = {c.first + dy[d], c.second + dx[d]};
                    if(bitmap[n.first][n.second] != -1
                        && !visited[n.first][n.second]) path.push(n);
                }
            }
        }
    }


    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            // cout << answer[r][c] << " ";
            printf("%d ", answer[r][c]);
        }
        // cout << "\n";
        printf("\n");
    }
    return 0;
}
