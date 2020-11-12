#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
 
using namespace std;
deque<int> circle[50];
int n; // 반지름이자, 원판의 갯수
int m; // 각 원판안에 들어있는 수의 갯수

int checkCircle(){
    int result = 0;
    bool ok[50][50] = {false,};
    // 같은 원 내에서 존재하는지 체크
    bool origin = true;
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(j == 0){
                if(circle[i][j] == circle[i][j+1] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][j+1] = true;}
                if(circle[i][j] == circle[i][m-1] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][m-1] = true;}
            } else if(j == m-1){
                if(circle[i][j] == circle[i][0] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][0] = true;}
                if(circle[i][j] == circle[i][j-1] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][j-1] = true;}
            } else {
                if(circle[i][j] == circle[i][j+1] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][j+1] = true;}
                if(circle[i][j] == circle[i][j-1] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i][j-1] = true;}
            }
        }
    }
    
    // 같은 순번에 내에서 존재하는지 체크
    for(int j=0; j < m; j++){
        for(int i=0; i < n; i++){
            if(i == 0){
                if(circle[i][j] == circle[i+1][j] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i+1][j] = true;}
            } else if(i == n-1){
                if(circle[i][j] == circle[i-1][j] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i-1][j] = true;}
            } else {
                if(circle[i][j] == circle[i+1][j] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i+1][j] = true;}
                if(circle[i][j] == circle[i-1][j] && circle[i][j] != 0) {origin = false; ok[i][j] = true; ok[i-1][j] = true;}
            }
        }
    }
    
    if(origin){
        int count = 0;
        for (int i=0; i < n; i++) {
            for(int j=0; j < m; j++){
                if(circle[i][j] != 0){
                    result += circle[i][j];
                    count++;
                }
            }
        }
        double aver = (double)result/(double)count;
        for (int i=0; i < n; i++) {
            for(int j=0; j < m; j++){
                if(circle[i][j] != 0){
                    if(circle[i][j] > aver) circle[i][j]--;
                    else if(circle[i][j] < aver) circle[i][j]++;
                }
            }
        }
    }
    
    result = 0;
    for (int i=0; i < n; i++) {
        for(int j=0; j < m; j++){
            if(ok[i][j] && circle[i][j] != 0) circle[i][j] = 0;
            else result += circle[i][j];
        }
    }

    return result;
}

int main() {
    cin >> n >> m;
    // (i, 1)은 (i, 2), (i, M)과 인접하다.        맨위는 왼쪽 오른쪽과 인접.
    // (i, M)은 (i, M-1), (i, 1)과 인접하다.      맨왼은 위쪽과 아래쪽과 인접.
    // (i, j)는 (i, j-1), (i, j+1)과 인접하다.    즉, 해당 순번은 j-1 과 j+1과 인접한것인데 M같은 경우는 1로 가야한다.
       
    // (i, j)는 (i-1, j), (i+1, j)와 인접하다.    서로 다른 원판이지만 같은 위치와 인접하다.
    // (N, j)는 (N-1, j)와 인접하다.              맨위 원판은 위가 존재하지 않으므로 아래만 존재.
    // (1, j)는 (2, j)와 인접하다.                위와 같지만 1일 경우 밑에는 존재 x 위에만 존재.
    
    int t; cin >> t; // t번 회전 시킨 후를 의미
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            int value; cin >> value;
            circle[i].push_back(value);
        }
    }

    int answer = 0;
    while (t--) {
        int x, d, k; // 원판 번호, d==0 시계 d==1 반시계, 몇번 돌것이냐.
        cin >> x >> d >> k;
        /*
        cout << "\n이동전\n";
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                cout << circle[i][j] << " ";
            }
            cout << "\n";
        }
        */
        if(x == 1){
            if(d == 0){
                for(int i=0; i < n; i++){
                    for(int j=0; j < k; j++){
                        circle[i].push_front(circle[i].back());
                        circle[i].pop_back();
                    }
                }
            } else {
                for(int i=0; i < n; i++){
                    for(int j=0; j < k; j++){
                        circle[i].push_back(circle[i].front());
                        circle[i].pop_front();
                    }
                }
            }
        } else {
            while (x <= n) {
                if(d == 0){
                    for(int i=0; i < k; i++){
                        circle[x-1].push_front(circle[x-1].back());
                        circle[x-1].pop_back();
                    }
                } else {
                    for(int i=0; i < k; i++){
                        circle[x-1].push_back(circle[x-1].front());
                        circle[x-1].pop_front();
                    }
                }
                x*=2;
            }
        }

/*
        cout << "\n이동후 값변경전\n";
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                cout << circle[i][j] << " ";
            }
            cout << "\n";
        }
  */
        answer = checkCircle();
 /*
        cout << "\n변경후\n";
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                cout << circle[i][j] << " ";
            }
            cout << "\n";
        }
*/
    }

    cout << answer << "\n";
    
    return 0;
}
