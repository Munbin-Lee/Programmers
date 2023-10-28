#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> room;

ll find(ll number) {
    if (!room[number]) return number;
    return room[number] = find(room[number]);
}

ll checkIn(ll number) {
    ll target = find(number);
    room[target] = target + 1;
    return target;
}

vector<ll> solution(ll k, vector<ll> numbers) {
    vector<ll> answer;
    answer.reserve(numbers.size());
    
    for (ll number : numbers) {
        answer.emplace_back(checkIn(number));
    }
    
    return answer;
}