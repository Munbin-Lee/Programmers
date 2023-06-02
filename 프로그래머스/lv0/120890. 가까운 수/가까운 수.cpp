#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int minDiff = INT32_MAX;
    int answer = INT32_MAX;
    for (int i : array) {
        int diff = abs(n - i);
        if (diff < minDiff) {
            minDiff = diff;
            answer = i;
        } else if (diff == minDiff) {
            answer = min(answer, i);
        }
    }
    return answer;
}