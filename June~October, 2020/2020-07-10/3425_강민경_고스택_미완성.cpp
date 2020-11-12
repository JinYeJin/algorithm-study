// 미완
// 3425 고스택 

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define MAX 1000000000
using namespace std;
 
stack<int> s;
vector<string> v;
 
// X를 스택의 가장 위에 저장한다. 
int NUM(int x){ 
  s.push(x);
  return 0;
}
 
// 스택 가장 위의 숫자를 제거한다.
int POP(){
	if (s.empty()) {
		return 1;
  }
  s.pop();
  return 0;
  }
 
//첫 번째 수의 부호를 바꾼다. (42 -> -42)
int INV(){ 
	if (s.empty()) {
		return 1;
	}
 
	int x = -(s.top());
	s.pop();
	s.push(x);
 
	return 0;
}
 
// 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
int DUP(){ 
	if (s.empty()) {
		return 1;
	}
 
	s.push(s.top());
 
	return 0;
}

 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 


}
