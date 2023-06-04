#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = min(sides[0], sides[1]) * 2 - 1;
    return answer;
}