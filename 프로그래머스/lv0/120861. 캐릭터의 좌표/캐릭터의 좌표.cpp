#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    unordered_map<string, pair<int, int>> mp = {
        {"up", {0, 1}},
        {"down", {0, -1}},
        {"left", {-1, 0}},
        {"right", {1, 0}}
    };
    
    pair<int, int> character, mx;
    mx = {board[0] / 2, board[1] / 2};
    
    for (string &key : keyinput) {
        character.first += mp[key].first;
        character.first = max(character.first, -mx.first);
        character.first = min(character.first, mx.first);
        character.second += mp[key].second;
        character.second = max(character.second, -mx.second);
        character.second = min(character.second, mx.second);
    }
    return {character.first, character.second};
}