#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    answer.reserve(commands.size());
    
    for (auto &command : commands) {
        int i, j, k;
        tie(i, j, k) = {command[0], command[1], command[2]};
        vector<int> subVector(&array[i - 1], &array[j]);
        sort(subVector.begin(), subVector.end());
        answer.emplace_back(subVector[k - 1]);
    }
    return answer;
}