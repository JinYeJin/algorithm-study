#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream = freopen("S2\\28\\input\\1931.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    vector<vector<int>> schedule(26);

    cin >> N;

    for(int n = 0; n < N; n++){
        int start, end;
        cin >> start >> end; 

        schedule[start].push_back(end);
    }

    for(int n = 0; n < N; n++){
        sort(schedule[n].begin(), schedule[n].end());
    }


    int total_meeting_room = 0;
    for(int i = 1; i <= 24; i++){
        int meeting_room = 0;

        for(int n = i; n <= 24;){
            if(schedule[n].size() != 0){
                n = schedule[n][0];
                meeting_room++;
            }
            else{
                n++;
                continue;
            }
        }

        total_meeting_room = total_meeting_room < meeting_room ? meeting_room : total_meeting_room;
    }

    cout << total_meeting_room;

    return 0;
}
