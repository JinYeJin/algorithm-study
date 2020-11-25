def solution(answers):
    students = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    marks = [ 0 for i in students ]

    for problem_num,sol in enumerate(answers):
        for stu_num,student in enumerate(students):
            if student[problem_num%len(student)] == sol:
                marks[stu_num] += 1 
    # max 메소드를 안쓰고서 최댓값이 1개인지, n개인지 반복문을 1번만 돌고서 확인하는 방법?
    # 중간에 배열을 clear해야할 수 있다.
    max_value = max(marks)  
    result = []
    for index, mark in enumerate(marks):    
        if max_value == mark:
            result.append(index+1)
    return result