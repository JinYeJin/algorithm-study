#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
    int count = 0;
    int j = 0;
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
    return count;
}

string getPageName(string parent){
    string pattern = "content=\"";
    vector<int> table = makeTable(pattern);
    int startIndex = 0;
    int parrentSize = parent.size();
    int patternSize = pattern.size();
    int count = 0;
    int j = 0;
    for(int i=0; i < parent.size();i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                startIndex = i-patternSize;
                j = table[j];
            } else {
                j++;
            }
        }
    }
    string remain = parent.substr(startIndex);
    vector<int> startEnd;
    int quotesCount = 0;
    for(int i=0; i < remain.size(); i++){
        if(remain[i] == '"') {
            quotesCount++;
            startEnd.push_back(i);
        }
        if(quotesCount == 2) break;
    }
    remain = remain.substr(startEnd[0]+9, startEnd[1]-startEnd[0]-9);
    
    return remain;
}

vector<string> exPageName(string parent){
    string pattern = "href=\"";
    vector<int> table = makeTable(pattern);
    vector<int> allStartIndex;
    int parrentSize = parent.size();
    int patternSize = pattern.size();
    int count = 0;
    int j = 0;
    for(int i=0; i < parent.size();i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                allStartIndex.push_back(i-patternSize);
                j = table[j];
            } else {
                j++;
            }
        }
    }
    
    vector<string> remains;
    for(int i=0; i < allStartIndex.size(); i++){
        string remain = parent.substr(allStartIndex[i]);
        vector<int> startEnd;
        int quotesCount = 0;
        for(int i=0; i < remain.size(); i++){
            if(remain[i] == '"') {
                quotesCount++;
                startEnd.push_back(i);
            }
            if(quotesCount == 2) break;
        }
        remains.push_back(remain.substr(startEnd[0]+9, startEnd[1]-startEnd[0]-9));
    }
    
    return remains;
}



int solution(string word, vector<string> pages) {
    int answer = 0;
    //string page;
    int pageSize = pages.size();
    
    vector<int> basicScore;
    vector<int> exSiteScore;
    vector<string> page;
    map<string, double> pageInfo;
    vector<string> exSites[pageSize];
    vector<double> Scores;

    for(int i=0; i < pageSize; i++){
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        basicScore.push_back(KMP(pages[i], word));
        exSiteScore.push_back(KMP(pages[i], "href"));
        page.push_back(getPageName(pages[i]));
        exSites[i] = exPageName(pages[i]);
        pageInfo[page[i]] = (double)basicScore[i]/exSiteScore[i];
    }

    for(int i=0; i < pageSize; i++){
        double score = basicScore[i];
        for(int j=0; j < exSites[i].size(); j++){
            score += pageInfo[exSites[i][j]];
        }
        Scores.push_back(score);
    }
    /*
    cout << Scores[0] << "\n";
    cout << Scores[1] << "\n";
    cout << Scores[2] << "\n";
    */
    
    return answer;
}


int main(){
    string word = "blind";
    
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>"
        
        , "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
        
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
    
    /*
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};
     */
    cout << solution(word, pages) << "\n";
}
