#include <iostream>
#include <vector>

using namespace std;

int row,col,hei,zero=0;

vector<vector<int>> red_tomato;
vector<vector<vector<int>>> arr;

vector<int> measure(int x, int y,int z){
    zero--;
    arr[z][y][x] = 1;
    
    vector<int> temp(3,x);
    temp[1] = y;
    temp[2] = z;
    return temp;
}
int main(int argc, const char * argv[]){
    int answer=0;

    cin>>row>>col>>hei;
    arr.resize(hei,vector<vector<int>>(col,vector<int>(row,0)));

    for(int z = 0; z<hei; z++)
        for(int y = 0; y<col; y++)
            for(int x = 0; x<row; x++){
                cin>>arr[z][y][x];
                if(arr[z][y][x] == 0) zero++;
                if(arr[z][y][x] == 1){
                    vector<int> temp(3,x);
                    temp[1] = y;
                    temp[2] = z;
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
            int x = temp[0], y = temp[1], z = temp[2];
            if(x-1>=0 and arr[z][y][x-1] == 0)
                next_red_tomato.push_back(measure(x-1,y,z));
            if(x+1<row and arr[z][y][x+1] == 0)
                next_red_tomato.push_back(measure(x+1,y,z));
            if(y-1>=0 and arr[z][y-1][x] == 0)
                next_red_tomato.push_back(measure(x,y-1,z));
            if(y+1<col and arr[z][y+1][x] == 0)
                next_red_tomato.push_back(measure(x,y+1,z));
            if(z-1>=0 and arr[z-1][y][x] == 0)
                next_red_tomato.push_back(measure(x,y,z-1));
            if(z+1<hei and arr[z+1][y][x] == 0)
                next_red_tomato.push_back(measure(x,y,z+1));
        }
        if(next_red_tomato.empty()){
            cout<< -1;
            return 0;
        }
        red_tomato = next_red_tomato;
        answer++;
    }
}
