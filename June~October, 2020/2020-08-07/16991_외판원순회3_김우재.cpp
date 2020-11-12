#include <iostream>
#include <vector>
#include <cmath>

#define MAX 16
#define INF 987654321

using namespace std;
int n;
int answer_bit;
double cost[MAX][1 << MAX];

double Min(double A, double B) { if (A < B) return A; return B; }

vector<pair<int, int>> map;
vector<pair<int, double>> list[16];

double dfs(int now, int bit){
    if(bit == answer_bit){
        if (list[now][0].second == 0) return INF;
        else return list[now][0].second;
    }
    if (cost[now][bit] != -1) return cost[now][bit]; // 메모라이제이션.
    cost[now][bit] = INF;
    
    for(int i=0; i < list[now].size(); i++){
        int next_node = list[now][i].first;
        double next_value = list[now][i].second;
        if (next_value == 0) continue;
        if ((bit & (1 << i)) == (1 << i)) continue; // 방문했던 적이 있으면
        cost[now][bit] = Min(cost[now][bit], next_value + dfs(next_node, bit | 1 << i));
    }
    return cost[now][bit];
}


int main(void){
    cin >> n;
    for(int i=0; i < n; i++){
        int x,y;
        cin >> x >> y;
        map.push_back(make_pair(x, y));
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            double distance =
            sqrt(pow(map[j].first - map[i].first, 2)+ pow(map[j].second - map[i].second, 2));
            list[i].push_back(make_pair(j, distance));
        }
    }
    answer_bit = (1 << n) - 1;
    
    for(int i=0; i < n; i++){
        for(int j=0; j < (1 << n); j++){
            cost[i][j] = -1.0;
        }
    }
    
    cout << fixed;
    cout.precision(6);
    cout << dfs(0, 1) << "\n";

    return 0;
}
