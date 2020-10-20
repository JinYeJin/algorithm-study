#include <iostream>
#include <vector>

using namespace std;
int N,d,k,c,sushi[30000],answer=0,kind_sushi=1;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>d>>k>>c;
    vector<int> event(d+1);
    for(int i=0;i<N;i++) cin>>sushi[i];
    event[c]++;
    for(int i=0;i<k;i++) if(0==event[sushi[i]]++) kind_sushi++;
    answer = max(answer, kind_sushi);
    for(int i=0;i<N;i++){
        if(0==--event[sushi[i]]) kind_sushi--;
        if(0==event[sushi[(i+k)%N]]++) kind_sushi++;
        answer = max(answer, kind_sushi);
    }
    cout<<answer;
    return 0;
}
