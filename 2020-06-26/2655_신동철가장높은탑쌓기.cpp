//Dp �� �ذ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class info {
public:
	int num;
	int area;
	int height;
	int weight;
	info(int num_, int area_, int height_, int weight_) :num(num_), area(area_), height(height_), weight(weight_) {}
};

int V; // ������ ��
vector<info> vec;//�Է¹޴� ����
vector <int> Dp[101];//�ε����� ������ȣ 1~100�� �ǹ� . �ε��� 0�� ����
vector <int> table[101];
int real_candidate = 0;
int real_maxv = 0;

void In() {
	cin >> V;
	int a, b, c;
	for (int tp = 1; tp <= V; tp++) {
		cin >> a >> b >> c;
		vec.push_back(info(tp, a, b, c));
	}
}


bool compare(info a, info b) {
	return a.weight < b.weight;
}


int main() {
	ios_base::sync_with_stdio(false);
	In();

	sort(vec.begin(), vec.end(), compare);//���Լ����� �������� ����
	
	if ( (int)vec.size() > 1) {//�������� �ּ� 2�����
		for (int tp = vec.size() - 1; tp >= 0; tp--) {
			int temp_area = vec[tp].area;
			int temp_num = vec[tp].num;
			int temp_height = vec[tp].height;


			table[temp_num].push_back(temp_height);
			Dp[temp_num].push_back(temp_num);

			int candidate = 0;
			int maxv = 0;
			for (int more_tp = tp + 1; more_tp < vec.size(); more_tp++) {//tp���� ū �ε��� more_tp�� ����
				if (temp_area < vec[more_tp].area)//���ظ������� more_tp�� �ε����� ���� vec �� ������ �� ũ�ٸ�
				{
					int buf_num = vec[more_tp].num;  //�̰Ͷ����� �ѹ�Ʋ���� !!!  �ε����� ��ȣ�� �߰����� 
					if (maxv < table[buf_num][0]) {//����
						maxv = table[buf_num][0];
						candidate = buf_num;
					}
				}
			}
			if (candidate != 0) {//�ĺ��ڰ� �ִٸ�
				table[temp_num][0] += maxv;
				for (int tp2 = 0; tp2 < Dp[candidate].size(); tp2++) {
					Dp[temp_num].push_back(Dp[candidate][tp2]);
				}
			}

			//������¿� ����.
			
			if ( real_maxv < table[temp_num][0]) {
				real_maxv = table[temp_num][0]; // �̰� ���� ��Ծ Ʋ�Ⱦ��� 
				real_candidate = temp_num;
			}

		}

		//���� �����
		cout << (int)Dp[real_candidate].size() << '\n';
		for (int tp = 0; tp < (int)Dp[real_candidate].size(); tp++)
			cout << Dp[real_candidate][tp] << '\n';

	}
	else if ((int)vec.size() == 1)//���� ������ 1�� �϶�
	{
		cout << '1' << '\n';
		cout << vec[0].num;
	}

}