#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_NUM 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N,H, result, min_result=MAX_NUM, cnt=0;
    
    cin>>N>>H;
    N/=2;
    
    int top[100000], bottom[100000];
    for(int i=0;i<N;i++)
        cin>>bottom[i]>>top[i];
    
    sort(top,top+N);
    sort(bottom,bottom+N);

    for(int i=0;i<H;i++){
        result = N-(int)(lower_bound(top, top+N,H-i)-top) +
                    N-(int)(lower_bound(bottom,bottom+N,1+i)-bottom);
        if(result==min_result) cnt++;
        else if(result<min_result){
            min_result=result;
            cnt=1;
        }
    }
    cout<<min_result<<" "<<cnt<<endl;
    return 0;
}
