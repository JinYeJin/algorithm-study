//성공
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstdlib>
#include <math.h>

#define LIMIT 1000000000

using namespace std;

stack<long long> go_stack;
queue<string>orders_qu;
int n;//입력수의 갯수
long long v;//cin에 이용될 단순변수임
void error() {
	cout << "ERROR" << '\n';
}
void program(long long val) {
	queue<string> copied_orders_qu;
	copied_orders_qu = orders_qu;// orders_qu 보존을 위하여 복사함

	go_stack.push(val);//최초의값 푸쉬

	//명령어들 수행
	while (!copied_orders_qu.empty()) {
		string k = copied_orders_qu.front();
		copied_orders_qu.pop();

		if (k.substr(0,3).compare("NUM") == 0) {
			long long x = atoll(k.substr(4,string::npos).c_str()); // x 숫자 추출
			//NUM x수행
			go_stack.push(x);
		}
		else if (k.compare("POP") == 0) {
			if ((int)go_stack.size() < 1) {
				error();
				return;
			}
			//POP수행
			go_stack.pop();
		}
		else if (k.compare("INV") == 0) {
			//INV수행
			if ( (int)go_stack.size() < 1) {
				error();
				return;
			}
			long long temp_ = (-1)*go_stack.top();
			go_stack.pop();
			go_stack.push(temp_);
		}
		else if (k.compare("DUP") == 0) {
			if ((int)go_stack.size() < 1) {
				error();
				return;
			}
			//DUP진행
			long long temp_ = go_stack.top();
			go_stack.push(temp_);

		}
		else if (k.compare("SWP") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}
			//SWP진행
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();
			go_stack.push(first);
			go_stack.push(second);
		}
		else if (k.compare("ADD") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}

			//ADD진행
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();

			//예외처리
			long long temp_ = second + first;
			if (abs(temp_) > LIMIT) {
				error();
				return;
			}

			go_stack.push(temp_);
		}
		else if (k.compare("SUB") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}

			//SUB진행
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();

			//예외처리
			long long temp_ = second - first;
			if (abs(temp_) > LIMIT) {
				error();
				return;
			}

			go_stack.push( temp_);
		}
		else if (k.compare("MUL") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}

			//MUL진행
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();
			//예외처리
			long long temp_ = second * first;
			if (abs(temp_) > LIMIT){
				error();
				return;
			}
			go_stack.push(temp_);
		}
		else if (k.compare("DIV") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}
			//DIV진행
			long long first = go_stack.top();
			go_stack.pop();
			if (first == 0)//0으로 나눌경우
			{
				error();
				return;
			}
			long long second = go_stack.top();
			go_stack.pop();
			long long sign = 1;
			if ((first < 0 && second>0) || (first > 0 && second < 0))//둘중 하나만 음수일때
				sign = -1;

			go_stack.push(sign* (abs(second) / abs(first)));
		}
		else if (k.compare("MOD") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}

			//MOD진행
			long long first = go_stack.top();
			go_stack.pop();
			if (first == 0)//0으로 나눌경우
			{
				error();
				return;
			}
			long long second = go_stack.top();
			go_stack.pop();

			long long sign = 1;
			if (second < 0)//부호 설정
				sign = -1;
			go_stack.push(sign* (abs(second) % abs(first)));
		}
		else {
		error();
		}

		
		//연산결과후 go_stack.size가 1이상 그리고 연산결과가 LIMIT를 넘을시 에러 .   (POP부분처리)
		if ( (go_stack.size()>=1) && (abs(go_stack.top()) > LIMIT))   //여기서 계속틀림!!
		{
			error();
			return;
		}

	}

	while (!copied_orders_qu.empty())//큐초기화
		copied_orders_qu.pop();

	//출력 및 오류검사
	if ((int)go_stack.size() == 1)
		cout << go_stack.top() << '\n';
	else {
		error();
		return;
	}


}
bool create_orders() {
	string k;
	while (1) {
		getline(cin, k);
		if (k == "")
			continue;
		if (k.compare("END") == 0)
			break;
		else if (k.compare("QUIT") == 0)
			return true;
		orders_qu.push(k);
	}
	return false;
}
void init_stack() {
	//고스택초기화
	while (!go_stack.empty())
		go_stack.pop();
}
void init_qu() {
	//명령어들초기화
	while (!orders_qu.empty())
		orders_qu.pop();
}
int main() {
	ios_base::sync_with_stdio(false);
	while (1) {
		if (create_orders() == false) {
			cin >> n;

			for (int tp = 1; tp <= n; tp++) {
				cin >> v;
				program(v);
				init_stack();//고스택초기화
			}
		}
		else
			break;//종료
			
		init_qu();//orders_qu초기화
		cout << '\n';//기계별 빈줄 구분
	}

	return 0;
}