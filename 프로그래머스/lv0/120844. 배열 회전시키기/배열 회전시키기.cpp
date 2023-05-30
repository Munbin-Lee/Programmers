#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    deque<int> dq(numbers.begin(), numbers.end());
    if (direction == "left") {
        dq.emplace_back(dq.front());
        dq.pop_front();
    } else {
        dq.emplace_front(dq.back());
        dq.pop_back();
    }
    vector<int> answer(dq.begin(), dq.end());
    return answer;
}