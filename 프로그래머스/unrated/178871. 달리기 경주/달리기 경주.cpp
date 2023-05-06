#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> ranks;
    for (int i = 0; i < players.size(); i++) {
        const string &player = players[i];
        ranks[player] = i;
    }
    
    for (const string &calling : callings) {
        int &passingRank = ranks[calling];
        const string &passedPlayer = players[passingRank - 1];
        int &passedRank = ranks[passedPlayer];
        swap(players[passingRank], players[passedRank]);
        swap(passingRank, passedRank);
    }
    return players;
}