#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string S,bomb,answer="";
    vector<int> st(1,-1);
    int idx;
    cin>>S>>bomb;
    for(char c:S){
        idx=st.back()+1;

        if(c == bomb[idx]){
            if(idx+1==bomb.size()){
                while(idx--){//폭발..
                    st.pop_back();
                    answer.pop_back();
                }
            }
            else{
                answer.push_back(c);
                st.push_back(idx);
            }
        }
        else{
            answer.push_back(c);
            st.push_back(c==bomb[0]?0:-1);
        }
    }
    cout<<(answer==""?"FRULA":answer);
    return 0;
}
