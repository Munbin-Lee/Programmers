def solution(sizes):
    max_x = 0
    max_y = 0
    
    for cur_x, cur_y in map(sorted, sizes):
        max_x = max(max_x, cur_x)
        max_y = max(max_y, cur_y)
    
    answer = max_x * max_y
    return answer