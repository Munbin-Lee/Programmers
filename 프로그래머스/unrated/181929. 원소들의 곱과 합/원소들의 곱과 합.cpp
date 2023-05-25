#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int prod = 1;
    int sum = 0;
    for (int num : num_list) {
        prod *= num;
        sum += num;
    }
    return prod < sum * sum;
}