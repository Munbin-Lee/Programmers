#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int slice, int n) {
    int answer = ceil(1.0 * n / slice);
    return answer;
}