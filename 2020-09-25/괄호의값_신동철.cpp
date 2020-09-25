#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> st;
int main() {
	int len,score=1;
	string k;
	cin >> k;
	len=k.length();
	for (int idx = 0; idx < len; idx++) {
		int loc_score = 1;
		if (!st.empty())//st저장된게 1개이상일때
		{
			if (st.top() == '(')//기존의 탑값
			{
				if(k[idx]=='(')
					
				if(k[idx]=='[')
				if(k[idx]==')')
				if(k[idx]==']')

			}
			if (st.top() == '[')
			{
				if (k[idx] == '(')
				if (k[idx] == '[')
				if (k[idx] == ')')
				if (k[idx] == ']')
			}

		}
		else {
			if (k[idx] == '(')
				loc_score *= 2;
			else if (k[idx] == '[')
				loc_score *= 3;
			else {
				cout << '0';
				return 0;
			}
				
			st.push(k[idx]);
			
		}
		//score += score + loc_score;
	}
	
	
}