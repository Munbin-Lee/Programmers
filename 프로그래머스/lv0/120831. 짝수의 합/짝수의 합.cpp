#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int lo = 2;
    int hi = (n | 1) - 1;
    int cnt = (hi - lo) / 2 + 1;
    int answer = (lo + hi) * cnt / 2;
    return answer;
}