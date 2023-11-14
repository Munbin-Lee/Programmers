class Student:
    id = -1
    pattern = []
    current_pattern_index = 0
    score = 0
    
    def __init__(self, id, pattern):
        self.id = id
        self.pattern = pattern
    
    def solve(self, answer):
        if answer == self.pattern[self.current_pattern_index]:
            self.score += 1
        self.current_pattern_index += 1
        self.current_pattern_index %= len(self.pattern)

def solution(answers):
    students = [
        Student(1, [1, 2, 3, 4, 5]),
        Student(2, [2, 1, 2, 3, 2, 4, 2, 5]),
        Student(3, [3, 3, 1, 1, 2, 2, 4, 4, 5, 5])
    ]
    
    for answer in answers:
        for student in students:
            student.solve(answer)
    
    maxScore = -1
    maxStudents = []
    
    for student in students:
        if student.score > maxScore:
            maxScore = student.score
            maxStudents = [student.id]
        elif student.score == maxScore:
            maxStudents.append(student.id)
    
    return maxStudents