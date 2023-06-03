#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (int num : array) {
        while (num) {
            answer += (num % 10 - 1) % 7 == 6;
            num /= 10;
        }
    }
    return answer;
}