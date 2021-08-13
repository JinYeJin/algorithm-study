#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

#define X(i) XYD[i][0]
#define Y(i) XYD[i][1]
#define D(i) XYD[i][2]

using namespace std;

vector<vector<int>> XYD;
map<pair<int,pair<int,int>>,int> MAP;
int N;
pair<int,pair<int,int>> meet_time(int i,int j){
    if(X(i)==X(j)){// ver | i값이 항상 값이작음
        if((D(i)==4 && D(j)==5) || (D(i)==8 && D(j)==7) || (D(i)==3 && D(j)==4) || (D(i)==1 && D(j)==8)){
            int a=Y(j)-Y(i);
            return make_pair(a, (D(i)==4?make_pair(X(i)+a,Y(i)):D(i)==8?make_pair(X(i)-a,Y(i)):D(i)==3?make_pair(X(i)+a,Y(j)):make_pair(X(i)-a,Y(j))));
        }
        if((D(i)==1 && D(j)==7) || (D(i)==2 && D(j)==6) || (D(i)==3 && D(j)==5)){
            if((Y(j)-Y(i))%2==0){
                int a=(Y(j)-Y(i))/2;
                return make_pair(a,make_pair(X(i)+(D(i)==1?-a:D(i)==2?0:a),Y(i)+a));
            }
        }
    }else if(Y(i)==Y(j)){// hor -- i값이 항상 값이작음
        if((D(i)==2 && D(j)==1) || (D(i)==6 && D(j)==7) || (D(i)==3 && D(j)==2) || (D(i)==5 && D(j)==6)){
            int a=X(j)-X(i);
            return make_pair(a, (D(i)==2?make_pair(X(i),Y(i)+a):D(i)==6?make_pair(X(i),Y(i)-a):D(i)==3?make_pair(X(j),Y(i)+a):make_pair(X(j),Y(i)-a)));
        }
        if((D(i)==3 && D(j)==1) || (D(i)==4 && D(j)==8) || (D(i)==5 && D(j)==7)){
            if((X(j)-X(i))%2==0){
                int a=(X(j)-X(i))/2;
                return make_pair(a,make_pair(X(i)+a,Y(i)+(D(i)==3?a:D(i)==4?0:-a)));
            }
        }
    }else if(X(i)-X(j)==Y(i)-Y(j)){// 대각선 /
        if((D(i)==2 && D(j)==8) || (D(i)==4 && D(j)==6) ){
            int a=X(j)-X(i);
            return make_pair(a, (D(i)==2?make_pair(X(i),Y(j)):make_pair(X(j),Y(i))));
        }
        if(D(i)==3 && D(j)==7){
            if((X(j)-X(i))%2==0){
                int a=(X(j)-X(i))/2;
                return make_pair(a,make_pair(X(i)+a,Y(i)+a));
            }
        }
    }else if(X(i)-X(j)==-Y(i)+Y(j)){// 대각선반대
        if((D(i)==4 && D(j)==2) || (D(i)==6 && D(j)==8) ){
            int a=X(j)-X(i);
            return make_pair(a, (D(i)==6?make_pair(X(i),Y(j)):make_pair(X(j),Y(i))));
        }
        if(D(i)==5 && D(j)==1){
            if((X(j)-X(i))%2==0){
                int a=(X(j)-X(i))/2;
                return make_pair(a,make_pair(X(i)+a,Y(i)-a));
            }
        }
    }
    return {-1,{0,0}};
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    FILE *stream =freopen("input.txt", "r", stdin);
    if(!stream) perror("freopen");
    cin>>N;
    XYD.resize(N,vector<int>(3));
    for(int i=0;i<N;i++){
        cin>>X(i)>>Y(i)>>D(i);
    }
    sort(XYD.begin(),XYD.end());
    pair<int,pair<int,int>> max_meet={0,{0,0}};
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            auto meet=meet_time(i,j);
            if(meet.first==-1) continue;
            MAP[meet]++;
            if(MAP[max_meet]<MAP[meet]){
                max_meet=meet;
            }
        }
    }
    cout<<MAP[max_meet]<<'\n'<<max_meet.first;
    return 0;
}
