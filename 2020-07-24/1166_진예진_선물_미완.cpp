#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\8\\input\\1166_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    long long N, L, W, H;

    // N: 정육면체의 박스의 개수, L, W, H: 직육면체 박스의 크기
    scanf("%d %d %d %d", &N, &L, &W, &H);

    double left = 0; 
    long long mid;
    double right = min(min(L, W), H);
    long long square_num;

    // 오차를 10 의 -9 승까지 허용
    while(right >= left){
        mid = (left + right) / 2;

        square_num = (L / mid) * (W / mid) * (H / mid);

        // 들어갈 수 있는 상자의 개수가 찾는 수인 N 보다 크거나 같은 경우 => 한 변이 mid 인 정육면체가 직육면체에 다 들어간다.
        if(square_num >= N) left = mid;
        else right = mid;
    }

    printf("%d", mid);

    return 0;
}
