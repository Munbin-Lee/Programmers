#include <string>
#include <vector>

using namespace std;

const int MAX_NUM = 1000000;
vector<bool> isPrime(MAX_NUM + 1, true);

void eratos() {
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX_NUM; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX_NUM; j += i) {
            isPrime[j] = false;
        }
    }
}

int solution(int n) {
    eratos();
    int answer = 0;
    for (int i = 1; i <= n; i++) answer += isPrime[i];
    return answer;
}