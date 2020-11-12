#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int T, chu;
    set<int> measure;
    scanf("%d",&T);
    while(T--!=0){
        scanf("%d", &chu);
        set<int> temp;
        for(int m: measure){
            temp.insert(m+chu);
            temp.insert(abs(m-chu));
        }
        for(int t:temp)
            measure.insert(t);
        measure.insert(chu);
    }
    
    scanf("%d",&T);
    while(T--!=0){
        scanf("%d", &chu);
        if (measure.find(chu) != measure.end())
            printf("Y ");
        else
            printf("N ");
    }

    return 0;
}
