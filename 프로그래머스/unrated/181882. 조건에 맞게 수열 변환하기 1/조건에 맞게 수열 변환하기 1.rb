def solution(arr)
    arr.map{ |x| transform(x) }
end

def transform(x)
    if x >= 50 && x.even?
        return x /= 2
    elsif x < 50 && x.odd?
        return x *= 2
    end
    return x
end