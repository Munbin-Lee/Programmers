#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    sort(dots.begin(), dots.end());
    int dx = dots[3][0] - dots[0][0];
    int dy = dots[1][1] - dots[0][1];
    int answer = dx * dy;
    return answer;
}