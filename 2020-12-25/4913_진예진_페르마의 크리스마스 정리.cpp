#include <stdio.h>
#include <iostream> 
#include <vector>
#include <string.h>

using namespace std;

bool check_prime[1000002];

int main(){
    FILE *stream =freopen("S2\\26\\input\\4913.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int L, U;
    vector<int> prime_numbers;

    cin >> L >> U;
    while(L != -1){
        int answer = 0;
        memset(check_prime, true, sizeof(check_prime));
        prime_numbers.clear();

        for(int i = 2; i <= U; i++){
            if(check_prime[i] == true){
                if(i >= L)
                    prime_numbers.push_back(i);
                for(int j = i*i; j <= U; j += i){
                    check_prime[j] = false;
                }
            }
        }


        for(auto iter = prime_numbers.begin(); iter != prime_numbers.end(); iter++){
            if(*iter%4 == 1) answer++;
        }
        
        cout << L << " " << U << " " << prime_numbers.size() << " " << answer << "\n";
        cin >> L >> U;
    }

    return 0;
}
