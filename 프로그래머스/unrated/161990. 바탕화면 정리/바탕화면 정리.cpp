#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int minY = INT32_MAX;
    int minX = INT32_MAX;
    int maxY = 0;
    int maxX = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '.') continue;
            minY = min(minY, i);
            minX = min(minX, j);
            maxY = max(maxY, i);
            maxX = max(maxX, j);
        }
    }
    vector<int> answer = {minY, minX, maxY + 1, maxX + 1};
    return answer;
}