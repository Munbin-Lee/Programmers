#include <string>
#include <vector>

#include <iostream>

using namespace std;

int choose(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return choose(n - 1, k) + choose(n - 1, k - 1);
}

int solution(int balls, int share) {
    int answer = choose(balls, share);
    return answer;
}