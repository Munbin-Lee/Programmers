#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while (order) {
        answer += (order % 10 - 1) % 3 == 2;
        order /= 10;
    }
    return answer;
}