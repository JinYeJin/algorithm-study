#include "bits/stdc++.h"

using namespace std;

char row[5][5]={0}, col[5][5]={0};

bool check(char* a){
    int answer=0;
    for(int i=0;i<5;i++) if(a[i]=='O') answer++;
    return answer==5;
}

int bingo(int i,int j){
    int r=0,c=0;
    for(int k=0;k<5;k++){
        if(row[i][k]=='O') r++;
        if(col[j][k]=='O') c++;
    }
    return (r==5)+(c==5);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,cnt=0,d1=0,d2=0;
    pair<int,int> location[25];
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>c;
            location[c-1]={i,j};
            row[i][j]='X';
            col[i][j]='X';
        }
    }
                    
    for(int k=1;k<=25;k++){
        cin>>c;
        int i=location[c-1].first, j=location[c-1].second;
        row[i][j]='O';
        col[j][i]='O';
        if(i==j) d1++;
        if(4-i==j) d2++;
        cnt+=bingo(i,j);
        if(cnt+(d1==5)+(d2==5)>2){
            cout<<k;
            break;
        }
    }
    return 0;
}
