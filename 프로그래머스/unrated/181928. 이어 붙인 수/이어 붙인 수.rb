def solution(num_list)
    odds = ""
    evens = ""
    for num in num_list
        num.odd? ? odds += num.to_s : evens += num.to_s
    end
    odds.to_i + evens.to_i
end