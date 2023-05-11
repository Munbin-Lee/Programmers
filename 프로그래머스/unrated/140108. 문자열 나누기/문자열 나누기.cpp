#include <string>
#include <vector>

#include <iostream>

using namespace std;

int decompose(int idx, const string &s) {
    if (idx == s.size()) return 0;
    char x = s[idx];
    int xCnt = 1;
    int notXCnt = 0;
    for (int i = idx + 1; i < s.size(); i++) {
        cout<<xCnt<<' '<<notXCnt<<'\n';
        if (xCnt == notXCnt) return decompose(i, s) + 1;
        s[i] == x ? xCnt++ : notXCnt++;
    }
    return 0;
}

int solution(string s) {
    int answer = decompose(0, s) + 1;
    return answer;
}