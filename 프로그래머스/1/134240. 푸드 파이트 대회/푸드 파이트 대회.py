def solution(foods):
    answer = []
    
    for food, num_food in enumerate(foods):
        answer.extend([str(food)] * (num_food // 2))
    
    
    answer.extend(['0'] + list(reversed(answer)))
    
    return ''.join(answer)