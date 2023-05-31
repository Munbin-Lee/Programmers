#include <string>
#include <vector>

using namespace std;

vector<bool> isPrime;

void eratos(int n) {
    isPrime.resize(n + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
}

vector<int> solution(int n) {
    eratos(n);
    vector<int> answer;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i] || n % i) continue;
        answer.emplace_back(i);
    }
    return answer;
}