#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    for (char& ch : s) {
        if (ch == ' ') {
            isFirst = true;
            continue;
        }
        if (isFirst) {
            isFirst = false;
            ch = toupper(ch);
        } else {
            ch = tolower(ch);
        }
    }
    return s;
}