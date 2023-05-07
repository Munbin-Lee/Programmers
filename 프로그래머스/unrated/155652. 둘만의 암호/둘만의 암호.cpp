#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string s, string skip, int index) {
    unordered_map<char, bool> skips;
    for (char ch : skip) {
        skips[ch] = true;
    }
    
    for (char &ch : s) {
        for (int i = 0; i < index;) {
            if (ch == 'z') ch = 'a';
            else ch++;
            
            if (!skips[ch]) i++;
        }
    }
    return s;
}