#include "/usr/local/include/bits/stdc++.h"

using namespace std;

string top="ABCDEFGHIJKLMNOPQRSTUVWXYZ", bottom;

char lad[1000][26];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    FILE *stream =freopen("/Users/sangoklee/Documents/workspace/test/test/test.txt", "r", stdin);
    if(!stream) perror("freopen");
    int k,n;
    
    cin>>k>>n;
    cin>>bottom;
    for(int i=0;i<n;i++){
        for(int j=1;j<k;j++){
            cin>>lad[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        if(lad[i][0]=='?') break;
        for(int j=0;j<k-1;j++){
            if(lad[i][j]=='-') swap(top[j],top[j+1]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(lad[i][0]=='?') break;
        for(int j=0;j<k-1;j++){
            if(lad[i][j]=='-') swap(bottom[j],bottom[j+1]);
        }
    }
    char answer[26];
    for(int j=0;j<k-1;j++){
        if(top[j]==bottom[j]){
            answer[j]='*';
            continue;
        }
        if(top[j]==bottom[j+1] && top[j+1]==bottom[j]){
            answer[j]='-';
            j++;
            continue;
        }

        for(int i=0;i<k-1;i++){
            answer[i]='x';
        }
        break;
    }
    answer[k-1]='\0';
    cout<<answer;
    
    return 0;
}
