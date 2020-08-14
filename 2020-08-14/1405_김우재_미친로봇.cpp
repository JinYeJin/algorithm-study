#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool passed[31][31];
int p[4];
int ret = 0;
double dfs(int n, int count, double per, int now_x, int now_y){
    if(passed[now_x][now_y]){
        return 0;
    }
    if(count == n){
        return per;
    }
    
    passed[now_x][now_y] = true;
    double ans = 0;
    for(int i=0; i<4; i++){
        int next_x = now_x + dx[i];
        int next_y = now_y + dy[i];
        if(next_x >= 0 && next_x < 31 && next_y >=0 && next_y < 31){
            ans += dfs(n, count+1, p[i] * per, next_x, next_y) * 0.01;
        }
    }
    passed[now_x][now_y] = false;
    return ans;
}

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<4; i++){
        cin >> p[i];
    }
    cout.precision(11);
    cout.fixed;
    cout << dfs(n, 0, 1, 15, 15) << "\n";
    return 0;
}
