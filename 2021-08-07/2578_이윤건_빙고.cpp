#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,cnt=0,d1=0,d2=0,row[5]={0},col[5]={0};
    pair<int,int> location[25];
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>c;
            location[c-1]={i,j};
        }
    }
                    
    for(int k=1;k<=25;k++){
        cin>>c;
        int i=location[c-1].first, j=location[c-1].second;
        if(i==j) d1++;
        if(4-i==j) d2++;
        cnt+=(++row[i]==5)+(++col[j]==5);
        if(cnt+(d1==5)+(d2==5)>2){
            cout<<k;
            break;
        }
    }
    return 0;
}
