#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer(&numbers[num1], &numbers[num2 + 1]);
    return answer;
}