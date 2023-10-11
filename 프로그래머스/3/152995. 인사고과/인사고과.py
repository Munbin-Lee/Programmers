def solution(scores):
    wanho = scores[0]
    
    rank = 1
    maxScore = 0
    
    for score in sorted(scores, key = lambda x : (-x[0], x[1])):
        if wanho[0] < score[0] and wanho[1] < score[1]:
            return -1
        if score[1] < maxScore:
            continue
        maxScore = score[1]
        if sum(wanho) < sum(score):
            rank += 1
    
    return rank