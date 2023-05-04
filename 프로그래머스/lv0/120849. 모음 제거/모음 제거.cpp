#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string solution(string my_string) {
    my_string.erase(remove_if(my_string.begin(), my_string.end(), isVowel),
                    my_string.end());
    return my_string;
}