#include <iostream>
#include <vector>

#define max(a, b) (a>b ? a:b)

using namespace std;

int row,col,global_zero;
vector<vector<int>> global_array;


int virus(vector<vector<int>>, int);
void infection( int, int);

int main(int argc, const char * argv[]){
    int zero=0, answer=0;
    
    cin>>col>>row;

    vector<vector<int>> arr(col, vector<int>(row,0));
    for(int y = 0; y<col; y++)
        for(int x = 0; x<row; x++){
            cin>>arr[y][x];
            if(arr[y][x] == 0) zero++;
        }
    
    //벽을 3개를 세울 수 있는 모든 경우의 수에 대해서 계산한다.
    for( int i = 0; i < col; i++)
        for(int j = 0; j < row; j++){
            if(arr[i][j] == 0){
                //---------------------------------첫번째 벽
                for(int i1 = i; i1<col; i1++)
                    for(int j1 = 0; j1<row; j1++){
                        if(!(i==i1 and j<=j1) and arr[i1][j1] == 0){
                            //---------------------------------두번째 벽
                            for(int i2 = i1; i2<col; i2++)
                                for(int j2 = 0; j2<row; j2++){
                                    if(!(i1==i2 and j1<=j2) and arr[i2][j2] == 0){
                                        vector<vector<int>> new_arr(col, vector<int>(row,0));
                                        for(int y = 0; y<col; y++)
                                            for(int x = 0; x<row; x++){
                                                new_arr[y][x] = arr[y][x];
                                            }
                                        
                                        
                                        new_arr[i][j] = 1; //1번째 벽
                                        new_arr[i1][j1] = 1; //2번째 벽
                                        new_arr[i2][j2] = 1; //3번째 벽 생성
                                        answer = max(answer, virus(new_arr, zero-3));
                                    }
                                }
                        }
                    }
            }
        }
    cout<<answer<<endl;
    return 0;
}

int virus(vector<vector<int>> array, int zero){
    global_array = array;
    global_zero = zero;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(array[i][j] == 2){
                infection(i,j);
            }
        }
    }
    return global_zero;
}
void infection(int i, int j){
    global_array[i][j] = 2;
    if(j-1>=0 and global_array[i][j-1] == 0){
        global_zero--;
        infection(i, j-1);
    }
    if(j+1<row and global_array[i][j+1] == 0){
        global_zero--;
        infection(i, j+1);
    }
    if(i-1>=0 and global_array[i-1][j] == 0){
        global_zero--;
        infection(i-1, j);
    }
    if(i+1<col and global_array[i+1][j] == 0){
        global_zero--;
        infection(i+1, j);
    }
}
