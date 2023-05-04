#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer;
    if (a == b && b == c && c == d) {
        answer = a * 1111;
    } else if (a == b && b == c) {
        answer = a * 10 + d;
        answer *= answer;
    } else if (a == b && b == d) {
        answer = a * 10 + c;
        answer *= answer;
    } else if (a == c && c == d) {
        answer = a * 10 + b;
        answer *= answer;
    } else if (b == c && c == d) {
        answer = b * 10 + a;
        answer *= answer;
    } else if (a == b && c == d) {
        answer = (a + c) * abs(a - c);
    } else if (a == c && b == d) {
        answer = (a + b) * abs(a - b);
    } else if (a == d && b == c) {
        answer = (a + b) * abs(a - b);
    } else if (a == b) {
        answer = c * d;
    } else if (a == c) {
        answer = b * d;
    } else if (a == d) {
        answer = b * c;
    } else if (b == c) {
        answer = a * d;
    } else if (b == d) {
        answer = a * c;
    } else if (c == d) {
        answer = a * b;
    } else {
        answer = min(a, b);
        answer = min(answer, c);
        answer = min(answer, d);
    }
    return answer;
}