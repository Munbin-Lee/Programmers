#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string res = n & 1 ? "odd" : "even";
    cout << n << " is " << res;
    return 0;
}