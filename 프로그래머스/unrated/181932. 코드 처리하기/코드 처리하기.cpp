#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    int mode = 0;
    string answer;
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == '1') {
            mode ^= 1;
        } else if (i % 2 == mode)  {
            answer += code[i];
        }
    }
    
    if (answer.empty()) answer = "EMPTY";
    return answer;
}