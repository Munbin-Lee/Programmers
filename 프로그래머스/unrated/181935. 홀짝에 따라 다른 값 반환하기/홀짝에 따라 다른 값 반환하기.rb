def solution(n)
    isEven = n.even?
    i = isEven ? 2 : 1
    sum = 0
    (i..n).step(2) do |i|
        i *= i if isEven
        sum += i
    end
    sum
end