#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i) continue;
        int q = sum / i;
        if ((q - 2) * (i - 2) == yellow) return {q, i};
    }
}