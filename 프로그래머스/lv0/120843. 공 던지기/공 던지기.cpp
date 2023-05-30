#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int idx = 0;
    idx += (k - 1) * 2;
    idx %= numbers.size();
    int answer = numbers[idx];
    return answer;
}