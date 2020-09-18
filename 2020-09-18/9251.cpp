/*
http://melonicedlatte.com/algorithm/2018/03/15/181550.html
위 링크 참고하였습니다
*/
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

char s1[1002], s2[1002];
int dp[1001][1001];

int main(){
    FILE *stream =freopen("S2\\15\\input\\9251.txt", "r", stdin);
    if(!stream) perror("freopen");

    // 문자열의 맨 앞에 0 을 넣어주려 주소값에 1 씩 더해줌
    scanf("%s %s", s1 + 1, s2 + 1);

    int i, j;

    // 각 for 문의 조건은 현재 i번째 문자열의 값이 0이 아니라면,
    // 즉 s1[i] != 0 과 같다
    for(i = 1; s1[i]; i++)
        for(j = 1; s2[j]; j++)
            // 현재 문자열이 같다면 +1 을 해주기 위해서 s1[i] == s2[j] 부분 들어감
            // 포스팅에는 문자열이 같다면/다르다면 두 가지 경우를 나눠서 설명했지만,
            // 점화식은 상관없이 셋중의 max를 구하는데, 이렇게 해도 상관없다.
            // 같던 다르던 0만 아니면 됨
            dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j],
                             dp[i - 1][j - 1] + (s1[i] == s2[j]) });
                             
    printf("%d", dp[i - 1][j - 1]);

    return 0;
}
