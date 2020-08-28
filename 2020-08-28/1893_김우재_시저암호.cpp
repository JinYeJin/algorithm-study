#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    
    int j = 0;
    for(int i=1; i < table.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}


int KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parrentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    int count = 0;
    for(int i=0; i < parent.size();i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                count++;
                j = table[j];
            } else {
                j++;
            }
        }
    }
    if(count == 1) return true;
    else return false;
}

void shift(map<char, int> &m, map<int, char> &m2, string &a, string &s){ // 딕셔너리, 순서, 큰글자들
    for(int j=0; j < s.size(); j++){
        if(s[j] == a[a.size()-1]){
            s[j] = a[0];
        }
        else s[j] = m2[m[s[j]]+1];
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string a,w,s; // 순서, 원문, 암호문
        cin >> a >> w >> s;
        vector<int> answer;
        
        map<char, int> m;
        map<int, char> m2;

        for(int i=0; i < a.size();i++){
            m.insert(make_pair(a[i], i));
            m2.insert(make_pair(i, a[i]));
        }
        
        for(int i=0; i < a.size();i++){
            if(KMP(s, w)){
                answer.push_back(i);
            }
            shift(m, m2, a, s);
        }
        
        if(answer.size() <= 0){
            cout << "no solution\n";
        }else if(answer.size() == 1){
            cout << "unique:";
            cout << " " << answer[0] << "\n";
        }else {
            cout << "ambiguous:";
            for(int j=0; j < answer.size(); j++){
                cout << " " << answer[j];
            }
            cout << "\n";
        }
    }
    return 0;
}

