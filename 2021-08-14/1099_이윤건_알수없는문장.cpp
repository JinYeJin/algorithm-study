#include "bits/stdc++.h";

using namespace std;

int get_cost(string a, string b) {
    int cnt=0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i]!=b[i]) cnt++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return (a==b?cnt:51);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, words[50];
    int N,answer=51;
    int visited[51];

    cin>>s;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>words[i];
    }
    for (int i = 0; i <= s.size(); i++) {
        visited[i]=51;
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});

    while (Q.size()) {
        auto q=Q.front();Q.pop();
        int i=q.first, total=q.second;
        
        for(int n=0;n<N;n++) {
            int cost=get_cost(s.substr(i,words[n].size()),words[n]);

            if(cost==51) continue;
            if(i+words[n].size()<=s.size()){
                if(visited[i + words[n].size()] > total + cost){
                    visited[i+words[n].size()]=total+cost;
                    Q.push({i+words[n].size(),total+cost});
                }
            }
        }
    }

    cout<<(visited[s.size()]==51?-1:visited[s.size()]);

    return 0;
}

///--개선

#include "bits/stdc++.h";

using namespace std;

int get_cost(string a, string b) {
    int cnt=0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i]!=b[i]) cnt++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return (a==b?cnt:51);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s, words[50];
    int N,DP[51];

    cin>>s;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>words[i];
    }
    for (int i = 1; i <= s.size(); i++) {
        DP[i]=51;
    }
    DP[0]=0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < N; j++) {
            int next = i+words[j].size();
            if(next>s.size()) continue; //정렬하면 시간을 아낄수 있지만 크기가 50밖에 안돼서 정렬안함.
            DP[next]=min(DP[next], DP[i]+get_cost(s.substr(i,words[j].size()), words[j]));
        }
    }
    cout<<(DP[s.size()]==51?-1:DP[s.size()]);

    return 0;
}
