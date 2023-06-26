def solution(n, control)
    control.each_char { |x|
        case x
            when "w"
                n += 1
            when "s"
                n -= 1
            when "d"
                n += 10
            when "a"
                n -= 10
        end
    }
    n
end