#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    do {
        answer += n % 10;
    } while (n /= 10);
    return answer;
}