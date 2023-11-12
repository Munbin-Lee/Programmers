#include <string>
#include <vector>
#include <queue>
// #include <unordered_map>

using namespace std;
using pr = pair<int, int>;

int solution(int x, int y, int n) {
    // unordered_map<int, int> map;
    // map[y] = 0;
    
    queue<pr> q;
    q.emplace(y, 0);
    
    while(!q.empty()) {
        auto [front, cnt] = q.front();
        q.pop();
        
        if(front == x) {
            // return map[front];
            return cnt;
        }
        
        if(front < x) continue;
        
        q.emplace(front - n, cnt + 1);
        if(front % 3 == 0) {
            // map[front / 3] = map[front] + 1;
            q.emplace(front / 3, cnt + 1);
        } 
        if(front % 2 == 0) {
            // map[front / 2] = map[front] + 1;
            q.emplace(front / 2, cnt + 1);
        }
        // if(map[front - n] == 0) {
        //     map[front - n] = map[front] + 1;
        //     q.emplace(front - n);
        // }
    }
    
    return -1;
}