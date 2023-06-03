#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    istringstream ss(my_string);
    int answer, num;
    char oper;
    ss >> answer;
    
    while (ss >> oper) {
        ss >> num;
        if (oper == '+') answer += num;
        else answer -= num;
    }
    return answer;
}