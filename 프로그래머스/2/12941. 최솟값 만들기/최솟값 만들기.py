def solution(A,B):
    sum = 0
    for a, b in zip(sorted(A), sorted(B, reverse=True)):
        sum += a * b
    return sum