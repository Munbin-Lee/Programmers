#include <string>
#include <vector>

using namespace std;

int answer;

void func(int idx, int cur, vector<int> &numbers, int target) {
    if (idx == numbers.size()) {
        if (cur == target) answer++;
        return;
    }
    
    func(idx+1, cur+numbers[idx], numbers, target);
    func(idx+1, cur-numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    func(0, 0, numbers, target);
    return answer;
}