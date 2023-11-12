def solution(k, m, score):
    answer = 0
    for minApple in sorted(score, reverse = True)[m - 1: (len(score) + 1) // m * m: m]:
        answer += minApple * m
    return answer