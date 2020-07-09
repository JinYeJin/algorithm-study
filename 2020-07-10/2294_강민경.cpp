// 2294 동전2
// https://www.acmicpc.net/problem/2294

#include <stdio.h>
using namespace std;

//d[x]=y => x원을 만드는데 필요한 최소 동전의 수 y
 
int min(int x, int y)
{
    return x < y ? x : y;
}
 
int main()
{
    int n, k;
    int coin[101] = { 0 };
    int arr[10001] = { 0 };
    scanf("%d %d", &n, &k);
    
    for (int i = 1;i <= n;i++) {
        scanf("%d", &coin[i]) ;
    }
    for (int i = 1;i <= k;i++) {
        arr[i] = 10000000;
    }
 
    arr[0] = 0;
 
    for (int i = 1;i <= n;i++) {
        for (int j = coin[i];j <= k;j++) {
            arr[j] = min(arr[j], arr[j - coin[i]] + 1);
        }
    }
 
    if (arr[k] == 10000000) {
        printf("-1\n");
    }
    else {
       printf("%d\n", arr[k]);
 
    }
}
