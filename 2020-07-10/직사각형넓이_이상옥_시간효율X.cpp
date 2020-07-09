// 정확성  테스트
// 테스트 1 〉	통과 (0.01ms, 3.82MB)
// 테스트 2 〉	통과 (0.01ms, 3.8MB)
// 테스트 3 〉	통과 (0.05ms, 3.88MB)
// 테스트 4 〉	통과 (0.10ms, 3.84MB)
// 테스트 5 〉	통과 (0.24ms, 3.88MB)
// 테스트 6 〉	통과 (0.37ms, 3.8MB)
// 테스트 7 〉	통과 (0.30ms, 3.81MB)
// 테스트 8 〉	통과 (0.75ms, 3.8MB)
// 테스트 9 〉	통과 (2.94ms, 3.87MB)
// 테스트 10 〉	통과 (3.79ms, 4.01MB)
// 테스트 11 〉	통과 (5.63ms, 3.98MB)
// 테스트 12 〉	통과 (4.71ms, 4.02MB)
// 테스트 13 〉	통과 (1.69ms, 3.97MB)
// 테스트 14 〉	통과 (0.02ms, 3.77MB)
// 테스트 15 〉	통과 (0.04ms, 3.88MB)
// 테스트 16 〉	통과 (0.97ms, 3.76MB)
// 테스트 17 〉	통과 (0.46ms, 3.77MB)
// 테스트 18 〉	통과 (0.43ms, 3.79MB)
// 테스트 19 〉	통과 (1.53ms, 3.94MB)
// 테스트 20 〉	통과 (0.15ms, 3.77MB)
// 테스트 21 〉	통과 (0.33ms, 3.92MB)
// 테스트 22 〉	통과 (0.23ms, 3.85MB)
// 테스트 23 〉	통과 (0.01ms, 3.84MB)
// 효율성  테스트
// 테스트 1 〉	실패 (시간 초과)
// 테스트 2 〉	통과 (839.35ms, 20MB)
// 테스트 3 〉	실패 (시간 초과)
// 테스트 4 〉	실패 (시간 초과)
// 테스트 5 〉	실패 (시간 초과)
    
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long answer=0;
int n;
vector<vector<int>> r;

long long area(vector<int> a){
    return (long long)((long long)(a[3]-a[1])*(long long)(a[2]-a[0]));
}
long long area(vector<int> a, vector<int> b){
    return (long long)((long long)(min(a[3],b[3])-max(a[1],b[1]))
        *(long long)(min(a[2],b[2])-max(a[0],b[0])));
}
bool compare(vector<int> a, vector<int> b){
    return  area(a)>area(b);
}
bool overlab(vector<int> a, vector<int> b){
    //0:x1, 1:y1, 2:x2, 3:y2  
    return !((a[2]<b[0]) or (a[3]<b[1]) or (b[2]<a[0]) or (b[3]<a[1]));
}
vector<int> left(vector<int> p, vector<int> r){
    p[0] = min(p[0],r[0]);
    p[2] = r[0];
    return p;
}
vector<int> right(vector<int> p, vector<int> r){
    p[0] = r[2];
    p[2] = max(p[2],r[2]);
    return p;
}
vector<int> up(vector<int> p, vector<int> r){
    p[0] = max(p[0],r[0]);
    p[1] = r[3];
    p[2] = min(p[2],r[2]);
    p[3] = max(p[3],r[3]);
    return p;
}
vector<int> down(vector<int> p, vector<int> r){
    p[0] = max(p[0],r[0]);
    p[1] = min(p[1],r[1]);
    p[2] = min(p[2],r[2]);
    p[3] = r[1];
    return p;
}
void start(int s,int x, vector<int> peace){
    if(peace[0]==peace[2] or peace[1]==peace[3]) return;
    long long ap = area(peace);
    for(int i=s; i<x; i++){
        if(overlab(peace, r[i])){
            ap -= area(peace, r[i]);
            start(i+1, x, left(peace,r[i]));
            start(i+1, x, right(peace,r[i]));
            start(i+1, x, up(peace,r[i]));
            start(i+1, x, down(peace,r[i]));
            return;
        }
    }
    answer+=ap;
}
long long solution(vector<vector<int>> rect)
{
    n=rect.size();
    r=rect;
    sort(r.begin(),r.end(), compare);

    for(int i=1; i<=n; i++)
        start(0, n-i, r[n-i]);
    return answer;
}
