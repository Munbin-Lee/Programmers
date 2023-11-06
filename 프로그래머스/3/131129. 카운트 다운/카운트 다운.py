from collections import defaultdict

def sm(a, b):
    return [a[0] + b[0], a[1] + b[1]]

def solution(target):
    # -(필요 다트 수), 싱글 또는 불을 맞춘 횟수
    memo = defaultdict(lambda : [-987654321, -987654321])
    memo[0] = [0, 0]
    memo[50] = [-1, 1]
    
    for point in range(1, 21):
        memo[point] = [-1, 1]
        memo[point * 2] = max(memo[point * 2], [-1, 0])
        memo[point * 3] = max(memo[point * 3], [-1, 0])
    
    for i in range(21, 60):
        for j in range(1, i):
            memo[i] = max(memo[i], sm(memo[i - j], memo[j]))
    
    answer = [-987654321, -987654321]
    
    # 50을 최대 5번 넣을 수 있다.
    for i in range(1, 6):
        tempTarget = target
        tempTarget -= 50 * i
        if (tempTarget < 0): break
        tempAnswer = [-i, i]
        tempAnswer[0] -= tempTarget // 60
        tempTarget %= 60
        tempAnswer = sm(tempAnswer, memo[tempTarget])
        answer = max(answer, tempAnswer)
    
    tempTarget = target
    tempAnswer = [0, 0]
    tempAnswer[0] -= tempTarget // 60
    tempTarget %= 60
    tempAnswer = sm(tempAnswer, memo[tempTarget])
    answer = max(answer, tempAnswer)
    
    answer[0] *= -1
    return answer