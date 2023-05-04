#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = num & 1 ? "Odd" : "Even";
    return answer;
}