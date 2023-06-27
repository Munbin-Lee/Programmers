#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    unordered_map<int, bool> visited;
    vector<int> answer;
    answer.reserve(k);
    for (int num : arr) {
        if (visited[num]) continue;
        visited[num] = true;
        answer.emplace_back(num);
        if (answer.size() == k) break;
    }
    answer.resize(k, -1);
    return answer;
}