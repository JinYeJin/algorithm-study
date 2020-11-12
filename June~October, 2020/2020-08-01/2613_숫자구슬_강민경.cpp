// 참고 https://beginthread.tistory.com/40
// https://www.acmicpc.net/problem/2613

#include<iostream>
using namespace std;
 
int n, m, i, j, a[301] = { 0 }, b[300];
 
bool go(int lim) {
    int cnt = m;
    i = 0;
    while (i < n) {
        j = n - cnt + 1;
        while (i<j && a[j] - a[i]>lim)--j;
        if (i == j)return false;
        b[--cnt] = j - i;
        i = j;        
    }
    return cnt == 0;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
 
    int l = 1, r = a[n];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (go(mid))r = mid - 1;
        else l = mid + 1;
    }
 
    cout << l << endl;
    go(l);
    for (int i = m - 1; i >= 0; --i)cout << b[i] << ' ';
}



/* 틀림
#include <stdio.h>
 
int n, m;
int input[301];
int ans;
 
int possible(int value)
{
    int i, sum, cnt;
 
    for (i = 0, sum = 0, cnt = 1; i < n - 1; i++) {
        sum += input[i];
        if (sum > value) {
            cnt++;
            sum = input[i];
        }
    }
    if (sum + input[i] > value)        cnt++;
 
    if (cnt <= m)    return 1;
    else    return 0;
}
 
void bsearch()
{
    int left = 0, right = n * 100, middle;
 
    ans = right;
    while (left <= right) {
        middle = (left + right) / 2;
        if (possible(middle)) {
            right = middle - 1;
            if (middle < ans)    ans = middle;
        }
        else    left = middle + 1;
    }
}
 
int main()
{
    int i, sum, cnt;
 
    scanf("%d %d", &n, &m);
 
    for (i = 0; i < n; i++)    scanf("%d", &input[i]);
 
    bsearch();
 
    printf("%d\n", ans);
 
    for (i = 0, sum = 0, cnt = 0; i < n; i++) {
        sum += input[i];
        if (sum > ans) {
            printf("%d ", cnt);
            sum = input[i];
            cnt = 0;
        }
        cnt++;
    }
    printf("%d\n", cnt);
 
    return 0;
}
*/
