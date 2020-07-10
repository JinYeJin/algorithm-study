//����
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
int n;//�Է¼��� ����
long long v;//cin�� �̿�� �ܼ�������
void error() {
	cout << "ERROR" << '\n';
}
void program(long long val) {
	queue<string> copied_orders_qu;
	copied_orders_qu = orders_qu;// orders_qu ������ ���Ͽ� ������

	go_stack.push(val);//�����ǰ� Ǫ��

	//��ɾ�� ����
	while (!copied_orders_qu.empty()) {
		string k = copied_orders_qu.front();
		copied_orders_qu.pop();

		if (k.substr(0,3).compare("NUM") == 0) {
			long long x = atoll(k.substr(4,string::npos).c_str()); // x ���� ����
			//NUM x����
			go_stack.push(x);
		}
		else if (k.compare("POP") == 0) {
			if ((int)go_stack.size() < 1) {
				error();
				return;
			}
			//POP����
			go_stack.pop();
		}
		else if (k.compare("INV") == 0) {
			//INV����
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
			//DUP����
			long long temp_ = go_stack.top();
			go_stack.push(temp_);

		}
		else if (k.compare("SWP") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}
			//SWP����
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

			//ADD����
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();

			//����ó��
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

			//SUB����
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();

			//����ó��
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

			//MUL����
			long long first = go_stack.top();
			go_stack.pop();
			long long second = go_stack.top();
			go_stack.pop();
			//����ó��
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
			//DIV����
			long long first = go_stack.top();
			go_stack.pop();
			if (first == 0)//0���� �������
			{
				error();
				return;
			}
			long long second = go_stack.top();
			go_stack.pop();
			long long sign = 1;
			if ((first < 0 && second>0) || (first > 0 && second < 0))//���� �ϳ��� �����϶�
				sign = -1;

			go_stack.push(sign* (abs(second) / abs(first)));
		}
		else if (k.compare("MOD") == 0) {
			if ((int)go_stack.size() < 2) {
				error();
				return;
			}

			//MOD����
			long long first = go_stack.top();
			go_stack.pop();
			if (first == 0)//0���� �������
			{
				error();
				return;
			}
			long long second = go_stack.top();
			go_stack.pop();

			long long sign = 1;
			if (second < 0)//��ȣ ����
				sign = -1;
			go_stack.push(sign* (abs(second) % abs(first)));
		}
		else {
		error();
		}

		
		//�������� go_stack.size�� 1�̻� �׸��� �������� LIMIT�� ������ ���� .   (POP�κ�ó��)
		if ( (go_stack.size()>=1) && (abs(go_stack.top()) > LIMIT))   //���⼭ ���Ʋ��!!
		{
			error();
			return;
		}

	}

	while (!copied_orders_qu.empty())//ť�ʱ�ȭ
		copied_orders_qu.pop();

	//��� �� �����˻�
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
	//�����ʱ�ȭ
	while (!go_stack.empty())
		go_stack.pop();
}
void init_qu() {
	//��ɾ���ʱ�ȭ
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
				init_stack();//�����ʱ�ȭ
			}
		}
		else
			break;//����
			
		init_qu();//orders_qu�ʱ�ȭ
		cout << '\n';//��躰 ���� ����
	}

	return 0;
}