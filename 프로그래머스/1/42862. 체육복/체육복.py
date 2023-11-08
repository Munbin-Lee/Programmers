from collections import deque

def solution(n, lost, reserve):
    # lost와 reserve를 비트마스킹으로 저장
    lostBit = 0
    reserveBit = 0
    
    for l in lost:
        lostBit |= (1 << l)
    
    for r in reserve:
        reserveBit |= (1 << r)
    
    # 여벌을 가져온 학생이 도난당한 경우
    intersection = lostBit & reserveBit
    lostBit ^= intersection
    reserveBit ^= intersection
    
    # 인덱스, 체육복을 가진 학생 수, 여벌 비트
    deq = deque([[1, 0, reserveBit]])
    answer = 0
    
    while deq:
        cur, curAnswer, curReserveBit = deq.popleft()
        
        # 도난당하지 않은 경우
        while (cur <= n) and not (lostBit & (1 << cur)):
            curAnswer += 1
            cur += 1
        
        if cur == n + 1:
            answer = max(answer, curAnswer)
            continue
        
        # 빌리지 않음
        deq.append([cur + 1, curAnswer, curReserveBit])
        
        # 빌림
        for giver in [cur - 1, cur + 1]:
            if not (curReserveBit & (1 << giver)): continue
            deq.append([cur + 1, curAnswer + 1, curReserveBit ^ (1 << giver)])
    
    return answer