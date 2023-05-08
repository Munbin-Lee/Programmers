#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int cacheSize;
list<string> caches;

string tolower(const string &s) {
    string res;
    for (char ch : s) {
        res += tolower(ch);
    }
    return res;
}

int getTime(const string &s) {
    auto it = find(caches.begin(), caches.end(), s);
    int res = -1;
    if (it == caches.end()) {
        caches.emplace_back(s);
        if (caches.size() > cacheSize) caches.pop_front();
        res = 5;
    } else {
        caches.erase(it);
        caches.emplace_back(s);
        res = 1;
    }
    return res;
}

int solution(const int _cacheSize, const vector<string> cities) {
    cacheSize = _cacheSize;
    int time = 0;
    for (const string &s : cities) {
        string city = tolower(s);
        time += getTime(city);
    }
    return time;
}