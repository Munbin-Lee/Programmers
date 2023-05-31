#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    answer.reserve(my_string.size());
    for (char ch : my_string) {
        if (!isdigit(ch)) continue;
        answer.emplace_back(ch - '0');
    }
    sort(answer.begin(), answer.end());
    return answer;
}