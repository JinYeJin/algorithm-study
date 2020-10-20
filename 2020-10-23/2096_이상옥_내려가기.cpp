#include <iostream>

#define max3(a,b,c) (a>b?a>c?a:c:b>c?b:c)
#define min3(a,b,c) (a<b?a<c?a:c:b<c?b:c)
using namespace std;

int N,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    cin>>a>>b>>c;
    int max_arr[2][3], min_arr[2][3];
    max_arr[0][0]=a,max_arr[0][1]=b,max_arr[0][2]=c,min_arr[0][0]=a,min_arr[0][1]=b,min_arr[0][2]=c;
    int i=1;
    for(;i<N;i++){
        cin>>a>>b>>c;
        max_arr[i&1][0]=a+max(max_arr[~i&1][0],max_arr[~i&1][1]);
        max_arr[i&1][1]=b+max3(max_arr[~i&1][0],max_arr[~i&1][1],max_arr[~i&1][2]);
        max_arr[i&1][2]=c+max(max_arr[~i&1][1],max_arr[~i&1][2]);
        
        min_arr[i&1][0]=a+min(min_arr[~i&1][0],min_arr[~i&1][1]);
        min_arr[i&1][1]=b+min3(min_arr[~i&1][0],min_arr[~i&1][1],min_arr[~i&1][2]);
        min_arr[i&1][2]=c+min(min_arr[~i&1][1],min_arr[~i&1][2]);
    }
    cout<<max3(max_arr[~i&1][0],max_arr[~i&1][1],max_arr[~i&1][2])<<' '<<min3(min_arr[~i&1][0],min_arr[~i&1][1],min_arr[~i&1][2]);
    return 0;
}
