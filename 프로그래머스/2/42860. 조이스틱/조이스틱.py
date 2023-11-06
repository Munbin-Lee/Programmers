from collections import deque

def solution(name):
    n = len(name)
    answer = 0
    flag = 0
    
    # 각 알파벳을 A로 만들기
    for idx, ch in enumerate(name):
        if ch == 'A': continue
        answer += min(
            ord(ch) - ord('A'),
            ord('Z') + 1 - ord(ch)
        )
        flag |= (1 << idx)
    
    # 현재 위치, 이동 횟수, 방문 필요 여부
    deq = deque([[0, 0, flag]])
    
    # BFS로 좌우 이동 횟수를 구함
    while deq:
        pos, cnt, nextFlag = deq.popleft()
        nextFlag &= ~(1 << pos)
        if nextFlag == 0: return answer + cnt
        deq.append([(pos + 1) % n, cnt + 1, nextFlag])
        deq.append([(pos - 1 + n) % n, cnt + 1, nextFlag])