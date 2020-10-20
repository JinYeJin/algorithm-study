#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int solution(vector<string> strs, string t)
{
    int answer = 0;
    map<string,bool> visited;

    queue<string> Q;
    Q.push("");

    while(Q.size()){
        int Q_size=Q.size();
        for(int i=0;i<Q_size;i++){
            string s=Q.front(); Q.pop();
            if(visited[s]) continue;
            visited[s]=true;
            if(s==t) return answer;
            for(string str:strs){
                if(visited[s+str]) continue;
                if(t.substr(s.size(),str.size())==str)
                    Q.push(s+str);
            }
        }
        answer++;
    }
    return -1;
}
