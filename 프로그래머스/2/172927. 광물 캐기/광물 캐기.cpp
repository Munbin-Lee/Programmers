#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 곡괭이로 광물을 캘 때 필요한 에너지

int energyNeeded[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

// mineral string 파싱용 map

unordered_map<string, int> mineralToInt = {
    {"diamond", 0},
    {"iron", 1},
    {"stone", 2}
};

int dfs(int idx, int energy, vector<int> picks, const vector<string>& minerals) {
    // 모든 광물을 캤을 경우
    
    if (idx >= minerals.size()) return energy;
    
    int minEnergy = 987654321;
    
    bool noPicks = true;
    
    for (int i = 0; i < 3; i++) {
        if (!picks[i]) continue;
        
        noPicks = false;
        
        // 광물 5개를 캔다.
        
        picks[i]--;
        int nextEnergy = energy;
        for (int j = idx; j < minerals.size() && j < idx + 5; j++) {
            nextEnergy += energyNeeded[i][mineralToInt[minerals[j]]];
        }
        minEnergy = min(minEnergy,
                        dfs(idx + 5, nextEnergy, picks, minerals));
        picks[i]++;
    }
    
    if (noPicks) return energy;
    
    return minEnergy;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = dfs(0, 0, picks, minerals);
    return answer;
}