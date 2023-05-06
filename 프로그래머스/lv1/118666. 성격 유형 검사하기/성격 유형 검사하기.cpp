#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<int, int> choiceToScore =
        {{1, 3}, {2, 2}, {3, 1}, {4, 0}, {5, 1}, {6, 2}, {7, 3}};
    unordered_map<char, int> scores;
    for (int i = 0; i < survey.size(); i++) {
        char disagree = survey[i][0];
        char agree = survey[i][1];
        int choice = choices[i];
        int score = choiceToScore[choice];
        if (choice <= 4) scores[disagree] += score;
        else scores[agree] += score;
    }
    
    vector<pair<char, char>> types =
        {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    string answer;
    for (auto &[type1, type2] : types) {
        int score1 = scores[type1];
        int score2 = scores[type2];
        if (score1 >= score2) answer += type1;
        else answer += type2;
    }
    return answer;
}