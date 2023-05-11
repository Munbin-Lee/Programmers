#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
    if (!b) return a;
    return getGCD(b, a % b);
}

int solution(vector<int> arr) {
    int lcm = 1;
    for (int n : arr) {
        int gcd = getGCD(lcm, n);
        lcm *= n / gcd;
    }
    return lcm;
}