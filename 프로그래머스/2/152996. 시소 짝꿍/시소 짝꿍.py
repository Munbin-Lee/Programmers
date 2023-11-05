from collections import defaultdict

def solution(weights):
    answer = 0
    counts = defaultdict(int)
    for weight in weights:
        answer += counts[weight]
        answer += counts[weight * 2]
        answer += weight % 2 == 0 and counts[weight // 2] or 0
        answer += weight % 2 == 0 and counts[weight // 2 * 3] or 0
        answer += weight % 3 == 0 and counts[weight // 3 * 2] or 0
        answer += weight % 3 == 0 and counts[weight // 3 * 4] or 0
        answer += weight % 4 == 0 and counts[weight // 4 * 3] or 0
        counts[weight] += 1
    return answer