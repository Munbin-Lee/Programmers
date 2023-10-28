#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using Range = pair<ll, ll>;

auto cmp = [] (const Range &a, const Range &b) {
    return a.second < b.second;
};

set<Range, decltype(cmp)> renges(cmp);

void safeInsert(ll a, ll b) {
    if (a > b) return;
    renges.insert({a, b});
}

ll checkIn(ll number) {
    auto it = renges.upper_bound({-1, number - 1});
    ll a = it->first; ll b = it->second;
    renges.erase(it);
    ll target = max(a, number);
    safeInsert( a, target - 1);
    safeInsert( target + 1, b);
    return target;
}

vector<ll> solution(ll k, vector<ll> numbers) {
    renges.insert({1, k});
    vector<ll> answer;
    answer.reserve(numbers.size());

    for (ll number : numbers) {
        answer.emplace_back(checkIn(number));
    }

    return answer;
}

int main() {
    ll k = 10;
    vector<ll> numbers = {
            1,3,4,1,3,1
    };
    for (auto i :solution(k, numbers)) {
        cout << i << ' ';
    }
}