#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int k = num_list.size();
    vector<vector<int>> answer;
    answer.reserve(k / n);
    for (int i = 0; i < k; i += n) {
        vector<int> subVector(&num_list[i], &num_list[i + n]);
        answer.emplace_back(subVector);
    }
    return answer;
}