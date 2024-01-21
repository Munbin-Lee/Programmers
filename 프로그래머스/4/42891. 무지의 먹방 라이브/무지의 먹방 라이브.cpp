#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 브루트포스
// O(k) == 10조

// int solution(vector<int> food_times, long long k) {
//     queue<pair<int, int>> q;
    
//     for (int i = 0; i < food_times.size(); i++) {
//         q.emplace(i + 1, food_times[i]);
//     }
    
//     while (!q.empty() && k--) {
//         auto [index, time] = q.front();
//         q.pop();
        
//         if (time == 1) continue;
        
//         q.emplace(index, time - 1);
//     }
    
//     if (q.empty()) return -1;
    
//     return q.front().first;
// }


// food_times의 최솟값부터 한번에 제거
// O(len(food_time)) == 20만

int solution(vector<int> food_times, long long k) {
    auto sorted_food_times = food_times;
    sort(sorted_food_times.begin(), sorted_food_times.end(), greater<>());
    
    int processed_food_time = 0;
    long cur_time = 0;
    
    while (!sorted_food_times.empty()) {
        int min_food_time = sorted_food_times.back();
        int period = min_food_time - processed_food_time;
        
        long next_time = cur_time + 1L * period * sorted_food_times.size();
        
        if (next_time > k) break;
        
        processed_food_time = min_food_time;
        
        while (sorted_food_times.back() == min_food_time) {
            sorted_food_times.pop_back();
        }
        
        cur_time = next_time;
    }
    
    if (sorted_food_times.empty()) return -1;
    
    int period = (k - cur_time) / sorted_food_times.size();
    cur_time += period * sorted_food_times.size();
    processed_food_time += period;
    
    for (int i = 0; i < food_times.size(); i++) {
        if (food_times[i] <= processed_food_time) continue;
        
        if (cur_time == k) return i + 1;
        
        cur_time++;
    }
    
    exit(2);
}