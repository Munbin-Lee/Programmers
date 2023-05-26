#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int i = 1; ; i++) {
        if (i * 6 % n == 0) return i;
    }
    return {};
}