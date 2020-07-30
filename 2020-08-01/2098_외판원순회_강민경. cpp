// https://yabmoons.tistory.com/358 [얍문's Coding World..]
// 비트 이해못함, 다시 풀기

#include<iostream>
#include<cstring>

#define MAX 16
#define INF 987654321
using namespace std;
 
int N, Answer_Bit;
int MAP[MAX][MAX];
int Cost[MAX][1 << MAX];
 
int Min(int A, int B) { if (A < B) return A; return B; }

int DFS(int Cur_Node, int Cur_Bit)
{
    if (Cur_Bit == Answer_Bit)
    {
        if (MAP[Cur_Node][0] == 0) return INF;
        else return MAP[Cur_Node][0];
    }
 
    if (Cost[Cur_Node][Cur_Bit] != -1) 
        return Cost[Cur_Node][Cur_Bit];
    
    Cost[Cur_Node][Cur_Bit] = INF;
    
    for (int i = 0; i < N; i++)
    {
        if (MAP[Cur_Node][i] == 0) continue;
        if ((Cur_Bit & (1 << i)) == (1 << i)) continue;
        
        Cost[Cur_Node][Cur_Bit] = Min(Cost[Cur_Node][Cur_Bit], MAP[Cur_Node][i] + DFS(i, Cur_Bit | 1 << i));
    }
    return Cost[Cur_Node][Cur_Bit];
}

 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // 입력 
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    Answer_Bit = (1 << N) - 1;
 
    // dfs
    memset(Cost, -1, sizeof(Cost));
    cout << DFS(0, 1) << endl;
    
    return 0;
}
