/*
세그먼트 트리 정리 https://www.crocus.co.kr/648
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define LM 1000000

using namespace std;

typedef long long ll;

ll val, a, b;
ll tree[4 * LM];

 
ll update(ll idx, ll val, ll node, ll start, ll end) {
    if (end < idx || idx < start)
        return tree[node];
    if (start == end)
        return tree[node] = val;
 
    ll mid = (start + end) >> 1;
    return tree[node] = (update(idx, val, node * 2, start, mid) 
        * update(idx, val, node * 2 + 1, mid + 1, end)) % MOD;
}
 
ll query(ll node, ll start, ll end, ll qLeft, ll qRight) {
    if (end < qLeft || qRight < start)
        return 1;
    if (qLeft <= start && end <= qRight)
        return tree[node];
 
    ll mid = (start + end) >> 1;
    return (query(node * 2, start, mid, qLeft, qRight) 
        * query(node * 2 + 1, mid + 1, end, qLeft, qRight)) % MOD;
}

int main(){
    FILE *stream =freopen("S2\\18\\input\\11505.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, N, M, K, cmd;
    cin >> N >> M >> K;
 
    for (i = 1; i <= N; i++) {
        cin >> val;
        update(i, val, 1, 1, N);
    }
    for (i = 0; i < M + K; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 1)
            update(a, b, 1, 1, N);
        else 
            cout << query(1, 1, N, a, b) << "\n";
    }
    return 0;
}
