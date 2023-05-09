#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    // ax + b
    int a = 0;
    int b = 0;
    stringstream ss(polynomial);
    string token;
    ss >> token;
    if (token == "x") a++;
    else if (token[token.size() - 1] == 'x') a += stoi(token);
    else b += stoi(token);
    while (ss >> token) {
        ss >> token;
        if (token == "x") a++;
        else if (token[token.size() - 1] == 'x') a += stoi(token);
        else b += stoi(token);
    }
    
    string answer;
    if (a == 0) {
        answer = to_string(b);
        return answer;
    }
    if (a == 1) answer = 'x';
    else if (a > 1) answer = to_string(a) + 'x';
    
    if (b) answer += " + " + to_string(b);
    return answer;
}