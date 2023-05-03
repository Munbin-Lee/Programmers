#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for (char& c : myString) {
        c = toupper(c);
    }
    return myString;
}