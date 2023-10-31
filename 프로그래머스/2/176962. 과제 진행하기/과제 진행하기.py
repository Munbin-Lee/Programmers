from collections import deque

def solution(plans):
    # 시간 문자열을 정수로 파싱
    for plan in plans:
        h, m = map(int, plan[1].split(':'))
        plan[1] = h * 60 + m
        plan[2] = int(plan[2])
    
    stack = []
    answer = []
    
    for plan in sorted(plans, key = lambda x : x[1]):
        if not stack:
            stack.append(plan)
            continue
        interval = plan[1] - stack[-1][1]
        while stack and interval >= stack[-1][2]:
            interval -= stack[-1][2]
            answer.append(stack.pop()[0])
        if stack:
            stack[-1][1] = plan[1]
            stack[-1][2] -= interval
        stack.append(plan)
    while stack:
        answer.append(stack.pop()[0])
    
    return answer