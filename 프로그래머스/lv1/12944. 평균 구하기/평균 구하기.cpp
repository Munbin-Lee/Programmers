#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    double answer = 1.0 * sum / arr.size();
    return answer;
}