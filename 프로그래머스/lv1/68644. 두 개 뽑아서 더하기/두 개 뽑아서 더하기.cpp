#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(vector<int> numbers) {
    array<bool, 201> exists {};
    for (int i = 0; i + 1 < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            exists[sum] = true;
        }
    }
    
    vector<int> res;
    res.reserve(201);
    for (int i = 0; i < 201; i++) {
        if (!exists[i]) continue;
        res.emplace_back(i);
    }
    return res;
}