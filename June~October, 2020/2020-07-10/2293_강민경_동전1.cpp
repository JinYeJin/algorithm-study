// 2293 동전1
#include <stdio.h>
using namespace std;

int main() {

    int i, j, n, k;
    int arr[10001] = {0, };

    scanf("%d %d", &n, &k);

    int coins[n];

    for (i = 0; i < n; i++) 
        scanf("%d", &coins[i]);
    
    arr[0] = 1;
    for (i = 0; i < n; i++) 
        for (j = coins[i]; j <= k; j++) 
            if (j - coins[i] >= 0) 
                arr[j] += arr[j - coins[i]];

    printf("%d\n", arr[k]);
    return 0;
}
