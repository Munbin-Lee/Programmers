#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (const string &s : quiz) {
        stringstream ss(s);
        string x, exp, y, equal, z;
        getline(ss, x, ' ');
        getline(ss, exp, ' ');
        getline(ss, y, ' ');
        getline(ss, equal, ' ');
        getline(ss, z, ' ');
        int X = stoi(x);
        int Y = stoi(y);
        int Z = stoi(z);
        bool isCorrect;
        if (exp == "+") {
            isCorrect = X+Y==Z;
        } else {
            isCorrect = X-Y==Z;
        }
        string res = isCorrect ? "O" : "X";
        answer.emplace_back(res);
    }
    return answer;
}