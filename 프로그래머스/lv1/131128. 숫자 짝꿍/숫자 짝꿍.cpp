#include <string>
#include <vector>
#include <array>

using namespace std;

string solution(string X, string Y) {
    array<int, 10> cntX {}, cntY {};
    for (char ch : X) {
        cntX[ch - '0']++;
    }
    for (char ch : Y) {
        cntY[ch - '0']++;
    }
    
    string answer;
    for (int i = 9; i >= 1; i--) {
        int cnt = min(cntX[i], cntY[i]);
        while (cnt--) answer += i + '0';
    }
    
    int cnt = min(cntX[0], cntY[0]);
    if (answer.empty() && !cnt) return "-1";
    if (answer.empty() && cnt) return "0";
    while (cnt--) answer += '0';
    return answer;
}