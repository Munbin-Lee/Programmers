#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    int lo = total / num + (1 - num) / 2;
    vector<int> answer(num);
    for (int i = 0; i < num; i++) {
        answer[i] = lo + i;
    }
    return answer;
}