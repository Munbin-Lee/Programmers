import re

def replace(m):
    a, b = m.groups()
    cnt = len(b) // len(a)
    return (cnt and str(cnt + 1) or '') + a

def solution(s):
    answer = len(s)
    for i in range(1, len(s) // 2 + 1):
        answer = min(answer, len(re.sub(r"([a-z]{%d})(\1*)" %i, replace, s)))
    return answer
