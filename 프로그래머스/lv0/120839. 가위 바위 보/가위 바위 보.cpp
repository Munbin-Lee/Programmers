#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string rsp) {
    unordered_map<char, char> mp = {
        {'0', '5'}, {'2', '0'}, {'5', '2'}
    };
    
    for (char &ch : rsp) {
        ch = mp[ch];
    }
    return rsp;
}