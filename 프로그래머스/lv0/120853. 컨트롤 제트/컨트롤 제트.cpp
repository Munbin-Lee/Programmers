#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int prev;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        if (token == "Z") {
            answer -= prev;
            continue;
        }
        int num = stoi(token);
        answer += num;
        prev = num;
    }
    return answer;
}