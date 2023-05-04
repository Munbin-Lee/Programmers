def solution(babbling):
    words = ["aya", "ye", "woo", "ma"]
    answer = 0
    for b in babbling:
        for word in words:
            b = b.replace(word, "TMP")
        b = b.replace("TMP", '')
        answer += len(b) == 0
    return answer