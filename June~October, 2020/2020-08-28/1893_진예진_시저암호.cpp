/*
[백준 1893 시저 암호] https://devbelly.tistory.com/25
참고 https://devbelly.tistory.com/25
KMP 알고리즘 1 https://bowbowbow.tistory.com/6
2 https://m.blog.naver.com/kks227/220917078260
*/
#include <vector>
#include <map>
#include <iostream>
using namespace std;
 
int tc;
 
string A, W, S;

int main() {
    FILE *stream =freopen("S2\\13\\input\\1893.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while (tc--) {
        vector<int> ans;
        cin >> A >> W >> S;
 
        // 사전의 내용을 저장 <현재문자, 다음문자>
        map<char, char> conv;
        int a_size = A.size();

        for (int i = 0; i < a_size; i++){ 
            // a의 크기로 나눠주어 배열의 인덱스를 넘어가는 것을 방지해준다.
            // A[A 배열의 최대 인덱스]인 경우 A 배열의 맨 앞의 값의 정보가 저장된다.
            conv[A[i]] = A[(i + 1) % a_size]; 
        }
        
        int w_size = W.size();

        // A 문자열의 길이만큼 옮겨서 A`를 만든다.
        // ABC, BCA, CAB
        for(int shift = 0; shift < a_size; shift++){
            if (shift != 0) {
                for (int k = 0;k < w_size;++k)
                    W[k] = conv[W[k]];
            }
 
            int fail[50001]{};
 
            // 새로운 W의 실패함수, KMP 알고리즘에서 prefix, sudix를 찾기위함?
            for (int i = 1, j = 0; i < w_size; i++) {
                while (j > 0 && W[i] != W[j]) j = fail[j - 1]; // 등가 연산자가 우선 실행
                if (W[i] == W[j]) fail[i] = ++j;
            }

            bool FIND = false;
            int s = S.size();
 
            //S에서 W를 찾는 kmp 알고리즘
            for (int i = 0, j = 0;i < s;++i) {
                while (j > 0 && S[i] != W[j]) j = fail[j - 1];
                if (S[i] == W[j]) {
                    // 마지막까지 찾았을 때
                    if (j == w_size - 1) {
                        //아직 못찾았다면 true
                        if (!FIND) {
                            FIND = true;
                            j = fail[j];
                        }
                        //이미 찾았는데 또 발견했다면 false
                        else {
                            FIND = false;
                            break;
                        }
                    }
                    else ++j;
                }
            }
            // 한개만 찾았다면 정답에 넣어주자
            if (FIND) 
                ans.emplace_back(shift);
        }
        
        // 정답 출력부
        if (ans.size() == 0) {
            cout << "no solution" << '\n';
        }
        else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (auto x : ans)
                cout << x << ' ';
            cout << '\n';
        }
    }
 
    return 0;
}
