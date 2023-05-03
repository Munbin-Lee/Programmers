#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    double answer = (double) sum / numbers.size();
    return answer;
}