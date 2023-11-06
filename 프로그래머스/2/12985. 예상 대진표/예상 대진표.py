def solution(n, a, b):
    answer = 0
    a, b = sorted([b, a])
    while True:
        if a == b: break
        a = (a + 1) // 2
        b = (b + 1) // 2
        answer += 1
    return answer