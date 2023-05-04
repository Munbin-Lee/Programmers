def solution(s):
    ls = map(int, s.split())
    ls = sorted(ls)
    answer = f"{ls[0]} {ls[-1]}" 
    return answer