from collections import defaultdict

def solution(names, yearnings, photos):
    dict = defaultdict(int)
    for name, yearning in zip(names, yearnings):
        dict[name] = yearning
    
    answer = []
    for photo in photos:
        sum = 0
        for person in photo:
            sum += dict[person]
        answer.append(sum)
    
    return answer