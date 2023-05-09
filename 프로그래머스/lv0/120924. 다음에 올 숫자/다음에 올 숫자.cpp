#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int d1 = common[1] - common[0];
    int d2 = common[2] - common[1];
    bool isArithmetic = d1 == d2;
    int answer;
    if (isArithmetic) {
        answer = common[common.size() - 1] + d1;
    } else {
        int r = common[1] / common[0];
        answer = common[common.size() - 1] * r;
    }
    return answer;
}