#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //이거 안쓰면 시간초과뜸.....
    
    map<int, int> card;
    int N, M;
    int term;
    cin>>N;
    for(int i =0; i<N; i++){
        cin>>term;
        if(card.find(term) == card.end())
            card.insert(make_pair(term,1));
        else
            card[term]++;
    }
    cin>>M;
    for(int i =0; i<M; i++){
        cin>>term;
        if(card.find(term) == card.end())
            cout<<0<<" ";
        else
            cout<<card[term]<<" ";
    }
    cout<<endl;
    return 0;
}


