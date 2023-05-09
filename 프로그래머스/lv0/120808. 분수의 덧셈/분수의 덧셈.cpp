#include <string>
#include <vector>

#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    if (b == 0) return a;
    
    return getGCD(b, a % b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int gcd = getGCD(denom1, denom2);
    int co1 = denom2 / gcd;
    int co2 = denom1 / gcd;
    numer1 *= co1;
    denom1 *= co1;
    numer2 *= co2;
    denom2 *= co2;
    int numer = numer1 + numer2;
    int denom = denom1;
    int gcd2 = getGCD(numer, denom);
    numer /= gcd2;
    denom /= gcd2;
    return {numer, denom};
}