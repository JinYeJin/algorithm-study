#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Hores{
    public:
        int roadNum;
        int index;
        bool finsish;
};

vector<int> road[4];
vector<int> dice(10);

int value[4] ={0,0,0,0};
Hores hores[4];

void goLast(int i){
    road[i].push_back(40);
    road[i].push_back(0);
}

void goMiddle(int i){
    road[i].push_back(25);
    road[i].push_back(30);
    road[i].push_back(35);
    goLast(i);
}

void init(){
    for(int i=0; i <= 38; i+=2){ road[0].push_back(i);}
    goLast(0);
    
    road[1].push_back(10);
    road[1].push_back(13);
    road[1].push_back(16);
    road[1].push_back(19);
    goMiddle(1);
    
    road[2].push_back(20);
    road[2].push_back(22);
    road[2].push_back(24);
    goMiddle(2);
    
    road[3].push_back(30);
    road[3].push_back(28);
    road[3].push_back(27);
    road[3].push_back(26);
    goMiddle(2);
    
    for(int i=0; i < dice.size(); i++){
        cin >> dice[i];
    }
    
}

int dfs(int index, Hores hores[], int value[]){
    int MaxValue = value[0]+value[1]+value[2]+value[3];
    if(index == 10) return MaxValue;
    
    for(int i=0; i < 4; i++){
        if(hores[i].finsish == true) continue;
        int tempNum = hores[i].roadNum;
        int tempIndex = hores[i].index;
        if(hores[i].roadNum == 0 && hores[i].index+dice[index] == 5){
            hores[i].roadNum = 1;
            hores[i].index = 1;
            value[i] += 10;
            MaxValue = max(MaxValue, dfs(index+1, hores, value));
            value[i] -= 10;
            hores[i].roadNum = tempNum;
            hores[i].index = tempIndex;
        } else if(hores[i].roadNum == 0 && hores[i].index+dice[index] == 10){
            hores[i].roadNum = 2;
            hores[i].index = 2;
            value[i] += 20;
            MaxValue = max(MaxValue, dfs(index+1, hores, value));
            value[i] -= 20;
            hores[i].roadNum = tempNum;
            hores[i].index = tempIndex;
        } else if(hores[i].roadNum == 0 && hores[i].index+dice[index] == 15){
            hores[i].roadNum = 3;
            hores[i].index = 3;
            value[i] += 30;
            MaxValue = max(MaxValue, dfs(index+1, hores, value));
            value[i] -= 30;
            hores[i].roadNum = tempNum;
            hores[i].index = tempIndex;
        }
        else {
            if(hores[i].index + dice[index] > road[hores[i].roadNum].size()) continue;
            if(hores[i].index + dice[index] == road[hores[i].roadNum].size()) hores[i].finsish = true;
            hores[i].index += dice[index];
            value[i] += road[hores[i].roadNum][hores[i].index];
            MaxValue = max(MaxValue, dfs(index+1, hores, value));
            value[i] -= road[hores[i].roadNum][hores[i].index];
            hores[i].index -= dice[index];
            hores[i].finsish = false;
        }
    }
    return MaxValue;
}

int main() {
    init();
    cout << dfs(0, hores, value) << "\n";
    
    return 0;
}
