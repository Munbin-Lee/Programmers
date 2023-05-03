#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1;
    for (; i * i < n; i++) {
        if (n % i == 0) answer += 2;
    }
    if (i * i == n) answer++;
    return answer;
}