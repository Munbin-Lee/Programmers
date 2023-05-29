#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = to_string(age);
    for (char &ch : answer) {
        ch += 'a' - '0';
    }
    return answer;
}