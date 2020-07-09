// 
#include <iostream>
#include <vector>
using namespace std;

long long solution(vector<vector<int> > rectangles)
{
    long long answer = 0;
    int visited_x[1000001] = {0,};
    int visited_y[1000001] = {0,};
    
    
    for(int i=0;i<rectangles.size(); i++){
        
        int width = rectangles[i][2] - rectangles[i][0];
        int height = rectangles[i][3] - rectangles[i][1];
        
        int temp_x = 0; // 겹치는 가로 길이
        int temp_y = 0; // 겹치는 세로 길이
        
        if(i==0){
            answer += (width * height);
            
            // 가로
            for(int j = rectangles[i][0]; j<= rectangles[i][2]; j++){
                int visited_x[j] = 1;
            }
            // 세로
            for(int j = rectangles[i][1]; j<= rectangles[i][3]; j++){
                int visited_y[j] = 1;
            }
        }
        
        // answer에 현재 사각형의 넓이를 더함 
        answer += (width * height);
        
        // 겹치는 넓이 체크
        // 가로
        for(int j = rectangles[i][0]; j<= rectangles[i][2]; j++){
            if(visited_x[j] == 0){
                int visited_x[j] = 1;
            }else{
                temp_x++;
            }  
              
        }
        // 세로
        for(int j = rectangles[i][1]; j<= rectangles[i][3]; j++){
             if(visited_y[j] == 0){
                int visited_y[j] = 1;
            }else{
                temp_y++;
            }  
        }
        
        answer -= (temp_x * temp_y);
    }

    return answer;
}
