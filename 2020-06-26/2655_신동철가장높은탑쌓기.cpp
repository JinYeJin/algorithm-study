//Dp 로 해결
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

int V; // 벽돌의 수
vector<info> vec;//입력받는 정보
vector <int> Dp[101];//인덱스는 벽돌번호 1~100을 의미 . 인덱스 0은 버림
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

	sort(vec.begin(), vec.end(), compare);//무게순으로 오름차순 정렬
	
	if ( (int)vec.size() > 1) {//벽돌수가 최소 2개라면
		for (int tp = vec.size() - 1; tp >= 0; tp--) {
			int temp_area = vec[tp].area;
			int temp_num = vec[tp].num;
			int temp_height = vec[tp].height;


			table[temp_num].push_back(temp_height);
			Dp[temp_num].push_back(temp_num);

			int candidate = 0;
			int maxv = 0;
			for (int more_tp = tp + 1; more_tp < vec.size(); more_tp++) {//tp보다 큰 인덱스 more_tp에 접근
				if (temp_area < vec[more_tp].area)//기준면적보다 more_tp를 인덱스로 갖는 vec 의 면적이 더 크다면
				{
					int buf_num = vec[more_tp].num;  //이것때문에 한번틀렸음 !!!  인덱스랑 번호랑 했갈려서 
					if (maxv < table[buf_num][0]) {//갱신
						maxv = table[buf_num][0];
						candidate = buf_num;
					}
				}
			}
			if (candidate != 0) {//후보자가 있다면
				table[temp_num][0] += maxv;
				for (int tp2 = 0; tp2 < Dp[candidate].size(); tp2++) {
					Dp[temp_num].push_back(Dp[candidate][tp2]);
				}
			}

			//정답출력용 갱신.
			
			if ( real_maxv < table[temp_num][0]) {
				real_maxv = table[temp_num][0]; // 이거 갱신 까먹어서 틀렸엇음 
				real_candidate = temp_num;
			}

		}

		//최종 답출력
		cout << (int)Dp[real_candidate].size() << '\n';
		for (int tp = 0; tp < (int)Dp[real_candidate].size(); tp++)
			cout << Dp[real_candidate][tp] << '\n';

	}
	else if ((int)vec.size() == 1)//벽돌 개수가 1개 일때
	{
		cout << '1' << '\n';
		cout << vec[0].num;
	}

}