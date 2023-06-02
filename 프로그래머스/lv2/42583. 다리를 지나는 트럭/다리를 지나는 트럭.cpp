#include <string>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

int maxLength, maxWeight, curWeight;
int answer = 1;
deque<int> dq;

void emplaceTruck(int truck) {
    dq.pop_back();
    dq.emplace_back(truck);
    curWeight += truck;
}

bool tryEmplaceTruck(int truck) {
    if (dq.back()) return false;
    if (curWeight + truck > maxWeight) return false;
    emplaceTruck(truck);
    return true;
}

void popTruck() {
    curWeight -= dq.front();
    dq.pop_front();
    dq.emplace_back(0);
    answer++;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    maxLength = bridge_length;
    maxWeight = weight;
    
    for (int i = 0; i < maxLength; i++) {
        dq.emplace_back(0);
    }
    
    for (int truck : truck_weights) {
        while (!tryEmplaceTruck(truck)) popTruck();
        auto q = dq;
        while (!q.empty()) {
            q.pop_front();
        }
    }
    
    answer += dq.size();
    return answer;
}