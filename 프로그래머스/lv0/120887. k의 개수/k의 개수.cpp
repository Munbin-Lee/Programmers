#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for (; i <= j; i++) {
        for (int l = i; l; l /= 10) {
            answer += l % 10 == k;
        }
    }
    return answer;
}