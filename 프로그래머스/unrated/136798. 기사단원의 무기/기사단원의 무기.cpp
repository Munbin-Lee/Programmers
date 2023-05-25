#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int getNumberOfDivisors(int x) {
    int res = 0;
    int i;
    for (i = 1; i * i <= x; i++) {
        res += (x % i == 0) * 2;
    }
    i--;
    if (i * i == x) res--;
    return res;
}

int solution(int number, int limit, int power) {
    int iron = 0;
    for (int i = 1; i <= number; i++) {
        int weapon = getNumberOfDivisors(i);
        if (weapon > limit) weapon = power;
        iron += weapon;
    }
    return iron;
}