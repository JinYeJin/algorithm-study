#include <stdio.h>
#include <climits>

int main(void){
    int k,n;
    long long wire[10001];
    long long max = 0;
    scanf("%d %d", &k, &n);
    
    for (int i = 0; i < k; i++)
        scanf("%lld", &wire[i]);
 
    long long left = 0;
    long long right = LLONG_MAX; // 최댓값 LLONG_MAX long long 형식 9,223,372,036,854,775,807
 
    while (left <= right){
        long long mid = (left + right) / 2;
        int result=0;
 
        for (int i = 0; i < k; i++)
            result += wire[i] / mid;
 
        if (result >= n)
        {
            left = mid + 1;
            if (mid > max)
                max = mid;
        }
        else
            right = mid - 1;
 
    }
 
    printf("%lld\n", max);
 
 
    return 0;
}


