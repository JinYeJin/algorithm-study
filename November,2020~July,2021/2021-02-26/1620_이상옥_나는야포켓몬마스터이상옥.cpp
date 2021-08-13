#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string dogam1[100000];
pair<string,int> dogam2[100000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,M;
    string s;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>dogam1[i];
        dogam2[i]={dogam1[i],i+1};
    }
    sort(dogam2,dogam2+N);
    for(int i=0;i<M;i++){
        cin>>s;
        if(isdigit(s[0])){
            cout<<dogam1[stoi(s)-1]<<'\n';
        }else{
            cout<<lower_bound(dogam2,dogam2+N,make_pair(s,0))->second<<'\n';
        }
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

string dogam1[100000];
unordered_map<string,int> dogam2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,M;
    string s;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>dogam1[i];
        dogam2[dogam1[i]]=i+1;
    }
    for(int i=0;i<M;i++){
        cin>>s;
        if(isdigit(s[0])){
            cout<<dogam1[stoi(s)-1]<<'\n';
        }else{
            cout<<dogam2[s]<<'\n';
        }
    }
    
    return 0;
}
