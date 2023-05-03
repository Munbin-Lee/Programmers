#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer (&num_list[n - 1], &num_list[num_list.size()]);
    return answer;
}