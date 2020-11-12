#include <stdio.h>
#include <string>

using namespace std;

int N;
string bar = "____";

string mul(string a, int b){
    string temp="";
    while(b--)
        temp+=a;
    return temp;
}
void DFS(int n){
    string temp;
    if(n==N){
        temp=mul(bar,n)+"\"재귀함수가 뭔가요?\"\n";
        printf("%s",temp.c_str());
        temp=mul(bar,n)+"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        printf("%s",temp.c_str());
        temp=mul(bar,n)+"라고 답하였지.\n";
        printf("%s",temp.c_str());
        return;
    }
    temp=mul(bar,n)+"\"재귀함수가 뭔가요?\"\n";
    printf("%s",temp.c_str());
    temp=mul(bar,n)+"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    printf("%s",temp.c_str());
    temp=mul(bar,n)+"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    printf("%s",temp.c_str());
    temp=mul(bar,n)+"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    printf("%s",temp.c_str());
    DFS(n+1);
    temp=mul(bar,n)+"라고 답하였지.\n";
    printf("%s",temp.c_str());
}
int main(){
    scanf("%d", &N);
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    DFS(0);
    return 0;
}

