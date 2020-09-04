#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool insert(int i, int j, int lsize, vector<vector<int>> board, vector<vector<int>> key){
    int ksize = key.size();
    
    for(int x=i, a=0; x < i+ksize; x++, a++){
        for(int y=j, b=0; y < j+ksize; y++, b++){
            board[x][y] = board[x][y] ^ key[a][b];
            if(!board[x][y] && key[a][b]) return false;
        }
    }
    
    for(int i=ksize-1; i < (lsize-1)+ksize; i++){
        for(int j=ksize-1, y=0; j < (lsize-1)+ksize;j++){
            if(board[i][j]==0) return false;
        }
    }
    
    return true;
}

vector<vector<int>> rotate(vector<vector<int>> nextkey){
    int ksize = nextkey.size();
    
    vector<vector<int>> result(ksize, vector<int>(ksize,0));
    
    for(int i=ksize-1; i >= 0; i--){
        for(int j=0; j < ksize; j++){
            result[j][i] = nextkey[i][ksize-j-1];
        }
    }
    

    
    return result;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock){

    int ksize = key.size();
    int lsize = lock.size();
    // 키사이즈, 락 사이즈
    
    vector<vector<int>> board((ksize*2)+(lsize-2), vector<int>((ksize*2)+(lsize-2), 0));
    // board를 확장시켜서 키운다.
    
    for(int i=ksize-1, x=0; i < (lsize-1)+ksize; i++, x++){
        for(int j=ksize-1, y=0; j < (lsize-1)+ksize;j++, y++){
            board[i][j] = lock[x][y];
        }
    }
    
    // board 에 lock을 채워넣는다.
    
    
    // 키를 기준으로 도는 것이다.
    for(int i=0; i < ksize+lsize-1; i++){
        for(int j=0; j< ksize+lsize-1; j++){
            vector<vector<int>> next_key = key;
            
            for(int k=0; k < 4; k++){
                if(insert(i,j,lsize,board,next_key)) return true;
                next_key = rotate(next_key);
            }
        }
    }
    
    return false;
}
