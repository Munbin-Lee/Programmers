#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include <iostream>

using namespace std;

int curDate;
unordered_map<char, int> periods;

bool isExpired(const string &privacy) {
    int year, month, day;
    char type;
    sscanf(privacy.c_str(), "%d.%d.%d %c", &year, &month, &day, &type);
    int date = year * 12 * 28 + month * 28 + day + periods[type];
    bool res = date <= curDate;
    return res;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int year, month, day;
    sscanf(today.c_str(), "%d.%d.%d", &year, &month, &day);
    curDate += year * 12 * 28 + month * 28 + day;
    
    for (const string &term : terms) {
        stringstream sin(term);
        char type;
        int period;
        sin >> type >> period;
        periods[type] = period * 28;
    }
    
    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) {
        if (isExpired(privacies[i])) {
            answer.emplace_back(i + 1);
        }
    }
    return answer;
}