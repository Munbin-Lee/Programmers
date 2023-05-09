#include <string>
#include <vector>

using namespace std;

bool isCursed(int n) {
    if (n % 3 == 0) return true;
    while (n) {
        if (n % 10 == 3) return true;
        n /= 10;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    while (n--) while (isCursed(++answer));
    return answer;
}