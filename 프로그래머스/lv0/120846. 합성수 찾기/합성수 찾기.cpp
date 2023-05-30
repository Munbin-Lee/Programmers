#include <string>
#include <vector>

using namespace std;

vector<bool> isPrime;

void eratos(int maxNumber) {
    isPrime.resize(maxNumber + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= maxNumber; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= maxNumber; j += i) {
            isPrime[j] = false;
        }
    }
}

int solution(int n) {
    eratos(n);
    int answer = n - 1;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) answer--;
    }
    return answer;
}