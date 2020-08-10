input1, input2 = list(map(int, input().split(" ")))
subjects_points = list(map(int, input().split(" ")))
students_points = list(map(int, input().split(" ")))


def maxCredit(subjects_points, students_points):
    cache = {}
    for stud_point in students_points:
        ans = 0
        for credit in subjects_points:
            if stud_point > credit: ans += 1
        cache[ans] = stud_point

    cache = sorted(cache)
    return cache[-1]

