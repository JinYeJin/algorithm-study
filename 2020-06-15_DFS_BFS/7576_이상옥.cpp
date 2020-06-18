#include <iostream>
#include <vector>

using namespace std;

int row,col,zero=0;

vector<vector<int>> red_tomato;
vector<vector<int>> arr;

vector<int> measure(int x, int y){
    zero--;
    arr[y][x] = 1;
    
    vector<int> temp(2,x);
    temp[1] = y;
    return temp;
}
int main(int argc, const char * argv[]){
    int answer=0;

    cin>>row>>col;
    arr.resize(col,vector<int>(row,0));

    for(int y = 0; y<col; y++)
        for(int x = 0; x<row; x++){
            cin>>arr[y][x];
            if(arr[y][x] == 0) zero++;
            if(arr[y][x] == 1){
                vector<int> temp(2,x);
                temp[1] = y;
                red_tomato.push_back(temp);
            }
        }
    while(1){
        vector<vector<int>> next_red_tomato;

        if(zero == 0){
            cout<<answer<<endl;
            return 0;
        }
        for(vector<int> temp : red_tomato){
            int x = temp[0], y = temp[1];
            if(x-1>=0 and arr[y][x-1] == 0)
                next_red_tomato.push_back(measure(x-1,y));
            if(x+1<row and arr[y][x+1] == 0)
                next_red_tomato.push_back(measure(x+1,y));
            if(y-1>=0 and arr[y-1][x] == 0)
                next_red_tomato.push_back(measure(x,y-1));
            if(y+1<col and arr[y+1][x] == 0)
                next_red_tomato.push_back(measure(x,y+1));
        }
        if(next_red_tomato.empty()){
            cout<< -1;
            return 0;
        }
        red_tomato = next_red_tomato;
        answer++;
    }
}
