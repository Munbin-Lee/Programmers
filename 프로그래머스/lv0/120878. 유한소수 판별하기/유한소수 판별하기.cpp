#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    if (!b) return a;
    return getGCD(b, a % b);
}

bool isFinite(int b) {
    while (b % 5 == 0) b /= 5;
    while (b % 2 == 0) b /= 2;
    return b == 1;
}

int solution(int a, int b) {
    b /= getGCD(a, b);
    int answer = isFinite(b) ? 1 : 2;
    return answer;
}