#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int prev = -1;
    vector<int> answer;
    answer.reserve(arr.size());
    for (int num : arr) {
        if (num == prev) continue;
        answer.emplace_back(num);
        prev = num;
    }
    return answer;
}