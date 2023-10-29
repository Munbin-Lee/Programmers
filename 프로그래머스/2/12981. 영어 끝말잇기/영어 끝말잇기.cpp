#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, bool> visited;
    char last = words[0][0];
    int number = 0;
    int round = 1;
    
    for (string &word : words) {
        if (visited[word] || word[0] != last) {
            return {number + 1, round};
        }
        visited[word] = true;
        last = word.back();
        number = (number + 1) % n;
        round += (number == 0);
    }
    
    return {0, 0};
}