#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    int answer;
    if (sides[2] < sides[0] + sides[1]) answer = 1;
    else answer = 2;
    return answer;
}