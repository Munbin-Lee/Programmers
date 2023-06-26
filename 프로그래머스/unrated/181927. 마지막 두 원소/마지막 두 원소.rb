def solution(num_list)
    num = num_list[-1] > num_list[-2] ? num_list[-1] - num_list[-2] : num_list[-1] * 2
    num_list << num
    return num_list
end