from collections import deque

def solution(name):
    cnt = 0
    targets = 0
    for idx, ch in enumerate(name):
        up = ord(ch) - ord('A')
        down = ord('Z') + 1 - ord(ch)
        dist = min(up, down)
        if dist == 0: continue
        cnt += dist
        targets |= (1 << idx)
    
    deq = deque([[0, 0, targets]])
    while deq:
        _cnt, pos, _targets = deq.popleft()
        _targets -= (_targets & (1 << pos))
        if _targets == 0: return cnt + _cnt
        left = pos - 1
        if left == -1: left = len(name) - 1
        deq.append([_cnt + 1, left, _targets])
        
        right = pos + 1
        if right == len(name): right = 0
        deq.append([_cnt + 1, right, _targets])
    return -1