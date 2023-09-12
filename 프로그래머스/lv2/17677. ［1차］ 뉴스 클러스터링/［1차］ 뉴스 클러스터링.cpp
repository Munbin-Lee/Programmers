#include <iostream>
#include <array>
#include <unordered_map>

using namespace std;

void tolower(string &s) {
    for (char &ch : s) {
        ch = tolower(ch);
    }
}

bool isProperSet(int lo, string &str) {
    for (int i : {lo, lo + 1}) {
        if (str[i] < 'a') return false;
        if (str[i] > 'z') return false;
    }
    return true;
}

int getSimilarity(array<string, 2> &strings) {
    array<unordered_map<string, int>, 2> maps;
    for (int i : {0, 1}) {
        auto &str = strings[i];
        auto &map = maps[i];
        for (int lo = 0, hi = 1; hi < str.size(); lo++, hi++) {
            if (!isProperSet(lo, str)) continue;
            string sub = str.substr(lo, 2);
            map[sub]++;
        }
    }
    
    unordered_map<string, int> unionMap;
    for (auto &map : maps) {
        for (auto &[k, v] : map) {
            unionMap[k] = max(maps[0][k], maps[1][k]);
        }
    }
    
    int unionCnt = 0;
    int intersectionCnt = 0;
    
    for (auto &[k, v] : unionMap) {
        unionCnt += v;
        intersectionCnt += min(maps[0][k], maps[1][k]);
    }
    
    if (!unionCnt) return 65536;
    
    int res = 65536.0 * intersectionCnt / unionCnt;
    return res;
}

int solution(string str1, string str2) {
    tolower(str1);
    tolower(str2);
    
    array<string, 2> strings = {
        str1, str2
    };
    
    int answer = getSimilarity(strings);
    return answer;
}