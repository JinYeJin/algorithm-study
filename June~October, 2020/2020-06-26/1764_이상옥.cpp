#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    set<string> not_listen;
    vector<string> result;
    string temp;
    int N, M;
    cin>>N>>M; //입력
    for(int i = 0; i<N; i++){
        cin>>temp;
        not_listen.insert(temp);
    }
    for(int i = 0; i<M; i++){
        cin>>temp;
        if(not_listen.erase(temp))
            result.push_back(temp);
    }

    cout<<result.size()<<endl;
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
    return 0;
}


