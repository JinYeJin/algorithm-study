#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int move(int p, int t, int s){
    return min(abs(t-p), abs(s-max(p,t)+min(p,t)));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M, p=0, value, answer=0,temp=0;
    cin>>N>>M;
    vector<int> queue(N);

    for(int i=0; i<N; i++)
        queue[i] = i+1;

    while(M--!=0){
        cin>>value;
        p=temp%(int)queue.size();
        auto it = find(queue.begin(), queue.end(), value);
        temp=(int)distance(queue.begin(),it);
        answer+=move(p,temp,(int)queue.size());
        queue.erase(it);
    }
    cout<<answer<<endl;
    return 0;
}
