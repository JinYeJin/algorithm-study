#include <stdio.h>
#include <iostream> 
#include <string.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\22\\input\\1138.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int people[12];
    int taller[12];

    cin >> N;

    memset(people, 0, sizeof(people));

    for(int i = 1; i <= N; i++){
        cin >> taller[i];
        people[i] = i;
    }

    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j++){
            if(people[j] < people[j+1]){
                    int temp = people[j+1];
                    people[j+1] = people[j];
                    people[j] = temp;

                    temp = taller[j+1];
                    taller[j+1] = taller[j];
                    taller[j] = temp;
            }
            else{
                if(taller[j] > 0){
                    int temp = people[j+1];
                    people[j+1] = people[j];
                    people[j] = temp;

                    taller[i]--;

                    temp = taller[j+1];
                    taller[j+1] = taller[j];
                    taller[j] = temp;
                }
            }
        }
        
    }

    for(int i = 1; i <= N; i++)
        cout << people[i] << "\n";
    return 0;
}
