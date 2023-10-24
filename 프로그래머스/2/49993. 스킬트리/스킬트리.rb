def solution(skill, skill_trees)
    answer = 0
    skill_trees.each {
        answer += skill.start_with?(_1.gsub(/[^#{skill}]/, '')) && 1 || 0
    }
    answer
end