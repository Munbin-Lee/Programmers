#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    array<array<char, 2>, 4> types =
        {{ {{'R', 'T'}}, {{'C', 'F'}}, {{'J', 'M'}}, {{'A', 'N'}} }};
    unordered_map<char, int> scores;
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] <= 4) scores[survey[i][0]] += 4 - choices[i];
        else scores[survey[i][1]] += choices[i] - 4;
    }
    
    string answer;
    for (int i = 0; i < 4; i++) {
        if (scores[types[i][0]] >= scores[types[i][1]]) answer += types[i][0];
        else answer += types[i][1];
    }
    return answer;
}