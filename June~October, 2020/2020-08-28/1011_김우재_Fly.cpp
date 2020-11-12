#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long from, to;
        cin >> from >> to;
        long long dest = abs(from-to);
        long long cnt = 0;
        if(dest == 1 || dest == 2 || dest == 3){cout << dest << "\n"; continue;}
        long long i=2;
        for(;i*i < dest;i++){}
        if(dest == i*i){ cnt = 1+(i-1)*2;}
        else {
            if(i*i -dest < i) cnt = 1+(i-1)*2;
            else cnt = (i-1)*2;
        }
        cout << cnt << "\n";
    }
    return 0;
}


