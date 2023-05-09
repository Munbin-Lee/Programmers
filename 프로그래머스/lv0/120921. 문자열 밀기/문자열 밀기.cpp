#include <string>
#include <vector>

using namespace std;

string shift(const string &s) {
    return s[s.size() - 1] + s.substr(0, s.size() - 1);
}

int solution(string A, string B) {
    string tempA = A;
    int answer = 0;
    while (A != B) {
        A = shift(A);
        answer++;
        if (answer > 100) return -1;
    }
    return answer;
}