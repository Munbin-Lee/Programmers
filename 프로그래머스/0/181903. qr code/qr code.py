def solution(q, r, code):
    return ''.join(k % q == r and v or '' for k, v in enumerate(code))