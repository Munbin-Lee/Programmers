#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int x = dot[0];
    int y = dot[1];
    int answer;
    if (x > 0 && y > 0) answer = 1;
    else if (x < 0 && y > 0) answer = 2;
    else if (x < 0 && y < 0) answer = 3;
    else if (x > 0 && y < 0) answer = 4;
    return answer;
}