#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

struct Cache {
    int cacheSize;
    list<string> ls;
    unordered_map<string, list<string>::iterator> mp;
    
    Cache(int cacheSize) : cacheSize(cacheSize) {}
    
    int refer(const string &s) {
        int time;
        if (mp.find(s) == mp.end()) {
            if (ls.size() == cacheSize) {
                mp.erase(ls.front());
                ls.pop_front();
            }
            ls.emplace_back(s);
            mp[s] = prev(ls.end());
            time = 5;
        } else {
            ls.erase(mp[s]);
            ls.emplace_back(s);
            mp[s] = prev(ls.end());
            time = 1;
        }
        return time;
    }
};

string tolower(const string &s) {
    string res;
    for (char ch : s) {
        res += tolower(ch);
    }
    return res;
}

int solution(const int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;
    
    auto cache = new Cache(cacheSize);
    int time = 0;
    for (string& city : cities) {
        city = tolower(city);
        time += cache->refer(city);
    }
    return time;
}