#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int answer = max(numbers[0] * numbers[1],
                     numbers.back() * numbers.rbegin()[1]);
    return answer;
}