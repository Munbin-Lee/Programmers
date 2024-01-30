def solution(people, limit):
    people.sort()
    lo = 0
    hi = len(people) - 1
    answer = 0
    
    while lo <= hi:
        if people[lo] + people[hi] <= limit: lo += 1
        hi -= 1
        answer += 1
    
    return answer