```py
from itertools import permutations as P

N=int(input())
dpL=[0]*(N+1)
dpR=[-101]*(N+1)
L,R=map(int, input().split())
cnt=0
for p in P(range(1,N+1),N):
    L_idx,n=0,0
    for i in p:
        if i>n:
            n=i
            L_idx+=1
    R_idx,n=0,0
    for i in p[::-1]:
        if i>n:
            n=i
            R_idx+=1
    if L==L_idx and R==R_idx: cnt+=1

print(cnt%1000000007)
```

풀이 보고 풀었음.
```c++
#include <iostream>
#include <string.h>

#define MOD 1000000007
using namespace std;

int N,L,R;
long dp[101][101][101];

long DFS(int N, int L, int R){
    if(N==0 or L==0 or R==0) return 0;
    long& def=dp[N][L][R];
    if(def==-1) def=(DFS(N-1,L-1,R)+DFS(N-1,L,R-1)+DFS(N-1,L,R)*(N-2))%MOD;
    return def;
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>L>>R;
    memset(dp,-1,sizeof(dp));
    dp[1][1][1]=1;
    cout<<DFS(N,L,R);
    return 0;
}

```

