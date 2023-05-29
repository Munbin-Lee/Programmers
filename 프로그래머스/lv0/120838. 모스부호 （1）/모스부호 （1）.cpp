#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

string solution(string letter) {
    unordered_map<string, char> morseToChar = {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, 
        {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, 
        {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, 
        {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'}, 
        {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, 
        {"--..", 'z'}
    };
    
    string answer, morse;
    stringstream sin(letter);
    
    while (sin >> morse) {
        answer += morseToChar[morse];
    }
    return answer;
}