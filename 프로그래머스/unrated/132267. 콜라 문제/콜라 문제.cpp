using namespace std;

int solution(int a, int b, int n) {
    int cnt = 0;
    while (n >= a) {
        n -= a;
        n += b;
        cnt += b;
    }
    return cnt;
}