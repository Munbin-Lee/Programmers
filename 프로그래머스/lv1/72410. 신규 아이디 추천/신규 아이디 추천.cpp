#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> allowedChars;

bool isAllowedChar(char ch) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        allowedChars.emplace_back(ch);
    }
    for (char ch = '0'; ch <= '9'; ch++) {
        allowedChars.emplace_back(ch);
    }
    allowedChars.emplace_back('-');
    allowedChars.emplace_back('_');
    allowedChars.emplace_back('.');
    
    for (char allowed : allowedChars) {
        if (ch == allowed) return true;
    }
    return false;
}

string solution(string new_id) {
    for (char &ch : new_id) {
        ch = tolower(ch);
    }
    
    new_id.erase(remove_if(new_id.begin(), new_id.end(),
        [](char ch) { return !isAllowedChar(ch); }), new_id.end());

    bool isPrevDot = false;
    string answer;
    for (char ch : new_id) {
        if (ch == '.' && !isPrevDot) {
            isPrevDot = true;
            answer += ch;
        } else if (ch != '.') {
            isPrevDot = false;
            answer += ch;
        }
    }
    
    if (answer[0] == '.') {
        answer = answer.substr(1);
    }
    if (answer[answer.size() - 1] == '.') {
        answer = answer.substr(0, answer.size() - 1);
    }
    
    if (answer.size() == 0) {
        answer = "aaa";
    } else if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if (answer[answer.size() - 1] == '.') {
            answer = answer.substr(0, answer.size() - 1);
        }
    } else while (answer.size() <= 2) {
        answer += answer[answer.size() - 1];
    }
    return answer;
}