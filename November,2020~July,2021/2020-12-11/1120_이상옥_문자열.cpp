#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 987654321
using namespace std;

string a, b;
int check(int bi){
    int score=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i+bi]){
            score++;
        }
    }
    return score;
}

int answer=INF;
int main(){
    cin>>a>>b;
    for(int i=0;i<=b.size()-a.size();i++){
        answer=min(answer, check(i));
    }
    cout<<answer;
    return 0;
}
