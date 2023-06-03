#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int s = sqrt(n);
    if (s * s == n) return 1;
    return 2;
}