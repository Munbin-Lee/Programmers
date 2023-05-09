#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string id = id_pw[0];
    string pw = id_pw[1];
    int level = 0;
    for (auto& v : db) {
        const string &try_id = v[0];
        const string &try_pw = v[1];
        if (id == try_id && pw == try_pw) {
            level = 2;
            break;
        } else if (id == try_id) {
            level = 1;
        }
    }
    if (level == 2) return "login";
    if (level == 1) return "wrong pw";
    return "fail";
}