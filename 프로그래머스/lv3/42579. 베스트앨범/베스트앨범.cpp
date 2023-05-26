#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> song; // play, idx
typedef pair<int, array<song, 2>> genre; // sumPlay, songs

int vCnt;
vector<genre> v;
unordered_map<string, int> mp;

int stringToInt(string &s) {
    if (mp.find(s) == mp.end()) {
        mp[s] = vCnt;
        genre pr = {0, array<song, 2>{make_pair(-1,-1), make_pair(-1,-1)}};
        v.emplace_back(pr);
        return vCnt++;
    } else {
        return mp[s];
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    v.reserve(100);
    
    int n = genres.size();
    for (int i = 0; i < n; i++) {
        int idx = stringToInt(genres[i]);
        auto &[p, songs] = v[idx];
        p += plays[i];
        if (plays[i] > songs[0].first) {
            songs[1] = songs[0];
            songs[0] = {plays[i], i};
        } else if (plays[i] > songs[1].first) {
            songs[1] = {plays[i], i};
        }
    }
    
    sort(v.begin(), v.end(), greater<>());
    vector<int> answer;
    answer.reserve(200);
    for (auto &[play, songs] : v) {
        for (auto [_, idx] : songs) {
            if (idx == -1) break;
            answer.emplace_back(idx);
        }
    }
    return answer;
}