#include "bits/stdc++.h";

using namespace std;

int cnt=10,N;
string answer="";

bool dfs(int i, int j) {
    if (i == 0) {
        if(cnt++ == N) return true;
        return false;
    }
    for (int k = 0; k < j; k++) {
        if(dfs(i-1, k)){
            answer=to_string(k)+answer;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>N;

    if(N<10){ //한자릿수는 규칙에서 벗어나서 따로 해줌.
        cout<<N;
        return 0;
    }

    for (int i = 2; i < 11; i++) { //자릿수 최대 9876543210 - 10개
        for(int j=1;j<10;j++){ //1-9 맨앞자리는 0이 올 수 없음.
            if(dfs(i-1, j)){
                answer=to_string(j)+answer;
                cout<<answer;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}
