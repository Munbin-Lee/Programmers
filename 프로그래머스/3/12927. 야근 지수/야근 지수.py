def solution(n, works):
    from collections import Counter
    work_remain_list = sorted(Counter(works).items())
    work_remain_list = [list(ele) for ele in work_remain_list]

    while n > 0 :
        time, amount = work_remain_list.pop()
        if n >= amount :
            if work_remain_list and work_remain_list[-1][0] == time -1:
                work_remain_list[-1][1] += amount
            else:
                work_remain_list.append([time-1,amount])
            n -= amount
        else:
            if work_remain_list and work_remain_list[-1][0] == time -1:
                work_remain_list[-1][1] += n
            else:
                work_remain_list.append([time-1,n])
            work_remain_list.append([time,amount-n])
            n -= amount

    if work_remain_list[-1][0] <=0: return 0
    result = 0
    for time, amount in work_remain_list:
        result+= amount*time**2
    return result