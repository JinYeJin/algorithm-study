#include <iostream>

#include <cstring> //memset

#include <algorithm>

using namespace std;

 

const int MAX = 30;

 

int weightNum, marbleNum; //추 개수, 구슬 개수

int weight[MAX]; //추

int marble[7]; //구슬

int cache[MAX + 1][MAX * 500 + 1]; //추의 갯수, 추의 갯수로 만들 수 있는 무게



void preCalculate(int currentWeightNum, int currentWeight) //현재 추의 갯수, 현재 만들어 낸 무게

{
        //기저 사례
        if (currentWeightNum > weightNum) // 추의 개수를 넘겼을 경우.
               return;

        int &result = cache[currentWeightNum][currentWeight]; // 이미 저장되면 사용
        if (result != -1)
               return; // 연산 하지 않고 넘기기

        // 현재 추의 개수 / 현재 무게를 아직 계산한적 없다면
        cache[currentWeightNum][currentWeight] = 1; //현재 만들어진 무게 기록

        //가능한 추의 갯수를 증가하고 해당 추를 구슬이 없는 저울에 올릴 경우 // 추 1개 증가시키기
        preCalculate(currentWeightNum + 1, currentWeight + weight[currentWeightNum]); // 증가
        
        //가능한 추의 갯수를 증가하지만 해당 추를 어느 저울에도 올리지 않을 경우
        preCalculate(currentWeightNum + 1, currentWeight); // 추 사용 안하겠다.

        //가능한 추의 갯수를 증가하고 해당 추를 구슬 쪽에 있는 저울에 올릴 경우
        preCalculate(currentWeightNum + 1, abs(currentWeight - weight[currentWeightNum]));

}

 

int main(void)

{
        cin >> weightNum; // 추의 무게.
        for (int i = 0; i < weightNum; i++)
               cin >> weight[i];

        cin >> marbleNum; // 구슬의 무게
        for (int i = 0; i < marbleNum; i++)
               cin >> marble[i];

        memset(cache, -1, sizeof(cache)); // dp -1로 초기화.

        preCalculate(0, 0); //모든 가능한 경우를 연산

        for (int i = 0; i < marbleNum; i++)

        {
               if (marble[i] > MAX * 500) //500g 추 30개를 추가한 것보다 무거운 구슬이라면
                       cout << "N ";
               else if (cache[weightNum][marble[i]] == 1)
                       cout << "Y ";
               else
                       cout << "N ";
        }
        cout << endl;
        return 0;
}
