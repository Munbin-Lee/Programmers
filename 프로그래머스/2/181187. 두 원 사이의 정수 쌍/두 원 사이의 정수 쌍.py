from math import sqrt

def 이하(r):
    res = 0
    for x in range(r):
        res += int(sqrt(r * r - x * x))
    return res * 4 + 1;

def 미만(r):
    res = 0
    for x in range(r):
        res += int(sqrt(r * r - x * x - 0.1))
    return res * 4 + 1;

def solution(r1, r2):
    a = 이하(r2)
    b = 미만(r1)
    print(a, b)
    return a - b